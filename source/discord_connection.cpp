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

bool DiscordConnection::p_setup;
TypeHandle DiscordConnection::_type_handle;

DiscordConnection::DiscordConnection() {

}

DiscordConnection::~DiscordConnection() {
    disconnect(); // Call disconnect function
}

/* 
 * Performs initial initialization of the discord-rpc library
 */
void DiscordConnection::connect(std::string application_id) {

    // Check if the rpc has been setup else where
    if (p_setup) {
        discord_cat.warning() << "Failed to setup DiscordConnection; a discord-rpc connection is already running!" << std::endl;
        return;
    }
    
    // Setup event handlers
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));

    // Initialize Discord library
    const char* c_application_id = application_id.c_str();
    Discord_Initialize(c_application_id, &handlers, 1, NULL);
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

    discord_cat.info("Shutting down...");
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
        discord_cat.warning() << "Updating rich presence..." << std::endl;
        Discord_UpdatePresence(&status->build_rich_presence());
        discord_cat.warning() << "WOAH!" << std::endl;
    } else {
        discord_cat.info() << "Clearing rich presence." << std::endl;
        Discord_ClearPresence();
    }
}

/*
 *  
 */
void DiscordConnection::respond(std::string userId, DiscordReply response) {

    // Verify we are currently setup
    if (!p_setup) {
        discord_cat.warning() << "Attempting to respond on a discord connection that is not initialized" << std::endl;
        return;
    }

    Discord_Respond(userId.c_str(), (int) response);
}
