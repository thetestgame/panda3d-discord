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

#ifndef _DISCORD_CONNECTION_H_
#define _DISCORD_CONNECTION_H_

#include "config_discord.h"
#include "rich_presence_status.h"
#include "discord_connection_user.h"

#include "pandabase.h"
#include "pandaFramework.h"
#include "typedReferenceCount.h"

#include "discord_rpc.h"

#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "time.h"

#define _CRT_SECURE_NO_WARNINGS

class DiscordConnection : public TypedReferenceCount {

    PUBLISHED:

        DiscordConnection();
        ~DiscordConnection();

        void connect(std::string application_id);
        void disconnect();
        void poll();

        void publish_status(RichPresenceStatus* status);

        // This enum contains every reply state for the Discord
        // connection.
        enum DiscordReply {
            DR_REPLY_NO = 1,
            DR_REPLY_YES = 2,
            DR_REPLY_IGNORE = 3
        };
        void respond(std::string userId, DiscordReply response);

        INLINE DiscordConnectionUser* get_connection_user();
        MAKE_PROPERTY(connection_user, get_connection_user);

    private:
        static bool p_setup;

        DiscordConnectionUser* p_connection_user;
    public:
        static TypeHandle get_class_type() {
            return _type_handle;
        }
        static void init_type() {
            TypedReferenceCount::init_type();
            register_type(_type_handle, "DiscordConnection",
                TypedReferenceCount::get_class_type());
        }
        virtual TypeHandle get_type() const {
            return get_class_type();
        }
        virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

    private:
        static TypeHandle _type_handle;
};

#include "discord_connection.I"

#endif