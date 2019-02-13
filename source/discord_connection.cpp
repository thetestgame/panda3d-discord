 /**
 * Author: Jordan Maxwell
 * Written: 02/11/2019
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2019 Nxt Games
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "discord_connection.h"
#include "throw_event.h"
#include "eventParameter.h"

DiscordConnection* DiscordConnection::p_global_ptr;
bool DiscordConnection::p_setup;
TypeHandle DiscordConnection::_type_handle;

/* 
 * Called when the connection is established. Throws an event
 * for Python code with the connected discord user passed in
 * as a DiscordConnectionUser object
 */
static void on_discord_ready(const DiscordUser* connectedUser) {
    DiscordConnection* discord_connection = DiscordConnection::get_global_ptr();
    discord_connection->set_connection_user(connectedUser);
    throw_event("discord-ready", discord_connection->get_connection_user());

    // Log connection
    discord_cat.info() << "Connected to user "
        << connectedUser->username 
        << "#" << connectedUser->discriminator 
        << " (" << connectedUser->userId << ")" << std::endl;
}

/*
 * Called on disconnect from the discord client
 */
static void on_discord_disconnected(int errcode, const char* message) {
    discord_cat.warning() << "Forced disconnect from client (" << errcode << "): " << message << "" << std::endl;
    DiscordConnection::get_global_ptr()->disconnect();
    throw_event("discord-force-disconnect", EventParameter(message), EventParameter(errcode));
}

/*
 * Called on discord-rpc library error. disconnects from the client and
 * fires a discord-error message
 */
static void on_discord_error(int errcode, const char* message) {
    discord_cat.error() << "discord-rpc error has occured (" << errcode << "): " << message << "" << std::endl;
    DiscordConnection::get_global_ptr()->disconnect();
    throw_event("discord-error", EventParameter(message), EventParameter(errcode));
}

/**
 * Called when the join button is pressed and accepted on the Discord
 * client.
 */
static void on_discord_join(const char* secret) {
    std::string python_secret(secret);
    discord_cat.info() << "Joining with secret: " << python_secret << std::endl;

    //TODO: perform callback
}

/**
 * Called when the spectate button is pressed and accepted on the
 * Discord client.
 */
static void on_discord_spectate(const char* secret) {
    std::string python_secret(secret);
    discord_cat.info() << "Spectating with secret: " << python_secret << std::endl;

    //TODO perform callback
}

/**
 * Called when a user requests to join the logged in users game
 * session
 */
static void on_discord_request_join(const DiscordUser* request) {
    DiscordConnectionUser* connection_user = new DiscordConnectionUser(request);
    discord_cat.info() << "Received join request from user: " << request->username << std::endl;

    //TODO perform callback
}

DiscordConnection::DiscordConnection() {}
DiscordConnection::~DiscordConnection() {
    disconnect(); // Call disconnect function
}

/*
 * Retrieves the current global DiscordConnection instance
 */
DiscordConnection* DiscordConnection::get_global_ptr() {
    if (p_global_ptr == nullptr) {
        p_global_ptr = new DiscordConnection();
    }
    return p_global_ptr;
}

/* 
 * Performs initial initialization of the discord-rpc library
 */
void DiscordConnection::connect(std::string application_id, std::string steamId) {

    // Check if the rpc has been setup else where
    if (p_setup) {
        discord_cat.warning() << "Failed to setup DiscordConnection; a discord-rpc connection is already running!" << std::endl;
        return;
    }
    
    // Setup event handlers
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    handlers.ready = on_discord_ready;
    handlers.disconnected = on_discord_disconnected;
    handlers.errored = on_discord_error;
    handlers.joinGame = on_discord_join;
    handlers.spectateGame = on_discord_spectate;
    handlers.joinRequest = on_discord_request_join;

    // Initialize Discord library
    Discord_Initialize(application_id.c_str(), &handlers, 1, steamId.c_str());
    discord_cat.info() << "discord-rpc connection established with application (" << application_id << ")" << std::endl;
    p_setup = true;
}

/* 
 * Performs shutdown operations for the Discord RPC library
 */
void DiscordConnection::disconnect() {

    // Verify we are currently setup
    if (!p_setup) {
        return;
    }

    discord_cat.info("Shutting down connection...");
    throw_event("discord-disconnect");
    Discord_Shutdown();
    p_setup = false;
}

 /* 
  * Performs update operations for the Discord RPC library
  */
void DiscordConnection::poll() {

    // Verify we are currently setup
    if (!p_setup) {
        return;
    }

    #ifdef DISCORD_DISABLE_IO_THREAD
        Discord_UpdateConnection();
    #endif
    Discord_RunCallbacks();
}

/*
 * Publishes the requested rich presence status to the Discord client
 */
void DiscordConnection::publish_status(RichPresenceStatus* status) {

    // Verify we are currently setup
    if (!p_setup) {
        discord_cat.warning() << "Attempted to update rich presence on an uninitialized discord-rpc connection" << std::endl;
        return;
    }

    if (status != nullptr) {
        discord_cat.info() << "Updating rich presence..." << std::endl;
        Discord_UpdatePresence(&status->build_rich_presence());
    } else {
        discord_cat.info() << "Clearing rich presence." << std::endl;
        Discord_ClearPresence();
    }
}

/*
 *  Respond to requested actions from Discord servers and clients
 */
void DiscordConnection::respond(std::string userId, DiscordReply response) {

    // Verify we are currently setup
    if (!p_setup) {
        discord_cat.warning() << "Attempting to respond on a discord connection that is not initialized" << std::endl;
        return;
    }

    Discord_Respond(userId.c_str(), (int) response);
}
