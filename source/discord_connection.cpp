 /**
 *  Author: Jordan Maxwell
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

bool DiscordConnection::b_setup;
TypeHandle DiscordConnection::_type_handle;

DiscordConnection::DiscordConnection() {

}

DiscordConnection::~DiscordConnection() {
    disconnect(); // Call disconnect function
}

/* 
 * Performs setup operations for the Discord RPC library
 */
void DiscordConnection::connect(std::string application_id, std::string steam_id) {

    // Check if the rpc has been setup else where
    if (b_setup) {
        discord_cat.warning() << "Failed to setup DiscordConnection; a discord-rpc connection is already running!" << std::endl;
        return;
    }

    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));

    Discord_Initialize(application_id.c_str(), &handlers, 1, steam_id.c_str());
    discord_cat.info() << "discord-rpc connection established." << std::endl;
    b_setup = true;
}

/* 
 * Performs shutdown operations for the Discord RPC library
 */
void DiscordConnection::disconnect() {

    // Verify we are currently setup
    if (!b_setup) {
        return;
    }

    discord_cat.info("Shutting down...");
    Discord_Shutdown();
    b_setup = false;
}



 /* 
  * Performs update operations for the Discord RPC library
  */
void DiscordConnection::update() {

    // Verify we are currently setup
    if (!b_setup) {
        return;
    }

    #ifdef DISCORD_DISABLE_IO_THREAD
        Discord_UpdateConnection();
    #endif
        Discord_RunCallbacks();
}

/*
 * Updates the current rich presence state for the connection
 */
void DiscordConnection::update_presence(RichPresenceStatus* status) {

    // Verify we are currently setup
    if (!b_setup) {
        discord_cat.warning() << "Attempted to update rich presence on an uninitialized discord-rpc connection" << std::endl;
        return;
    }

    discord_cat.info() << "Updating rich presence..." << std::endl;
    //Discord_UpdatePresence(&status->p_rich_presence); 
    //TEST
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "Example State";
    discordPresence.details = "Example Details";

    discord_cat.info() << "Setting Test Presence..." << std::endl;
    Discord_UpdatePresence(&discordPresence); 
}