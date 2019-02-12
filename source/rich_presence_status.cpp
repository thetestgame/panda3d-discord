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

#include "rich_presence_status.h"

TypeHandle RichPresenceStatus::_type_handle;

/*
 * Creates a DiscordRichPresence object for publishing to the Discord client
 * through a DiscordConnection object
 */
const struct DiscordRichPresence RichPresenceStatus::build_rich_presence() {

    // Build rich presence status
    DiscordRichPresence discord_presence;
    memset(&discord_presence, 0, sizeof(discord_presence));

    discord_presence.state = this->state.c_str();
    discord_presence.details = this->details.c_str();

    discord_presence.startTimestamp = this->startTimestamp;
    discord_presence.endTimestamp = this->endTimestamp;

    discord_presence.largeImageKey = this->largeImageKey.c_str();
    discord_presence.largeImageText = this->largeImageText.c_str();
    discord_presence.smallImageKey = this->smallImageKey.c_str();
    discord_presence.smallImageText = this->smallImageText.c_str();

    discord_presence.partyId = this->partyId.c_str();
    discord_presence.partySize = this->partySize;
    discord_presence.partyMax = this->partyMax;

    discord_presence.matchSecret = this->matchSecret.c_str();
    discord_presence.joinSecret = this->joinSecret.c_str();
    discord_presence.spectateSecret = this->spectateSecret.c_str();

    discord_presence.instance = this->instance;

    return discord_presence;
}