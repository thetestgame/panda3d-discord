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

#ifndef _DISCORD_CONNECTION_USER_H_
#define _DISCORD_CONNECTION_USER_H_

#include "config_discord.h"
#include "discord_rpc.h"
#include "typedReferenceCount.h"

#include "string.h"

/*
 *Forward declare DiscordUser for the interrogate
 *parser.
 */
struct DiscordUser;

/*
 * Panda wrapper class for the discord-rpc DiscordUser struct
 */
class DiscordConnectionUser : public TypedReferenceCount {

    public:
        INLINE std::string get_username();
        INLINE std::string get_discriminator();
        INLINE std::string get_user_id();
        INLINE std::string get_avatar();
        INLINE std::string get_discord_tag();

    PUBLISHED:

        MAKE_PROPERTY(username, get_username);
        MAKE_PROPERTY(discriminator, get_discriminator);
        MAKE_PROPERTY(user_id, get_user_id);
        MAKE_PROPERTY(avatar, get_avatar);
        MAKE_PROPERTY(discord_tag, get_discord_tag);

    public:
        DiscordConnectionUser(const DiscordUser *user);

    private:
        std::string username;
        std::string discriminator;
        std::string userId;
        std::string avatar;

    public:
        static TypeHandle get_class_type() {
            return _type_handle;
        }
        static void init_type() {
            TypedReferenceCount::init_type();
            register_type(_type_handle, "DiscordConnectionUser",
                TypedReferenceCount::get_class_type());
        }
        virtual TypeHandle get_type() const {
            return get_class_type();
        }
        virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

    private:
        static TypeHandle _type_handle;
};

#include "discord_connection_user.I"

#endif