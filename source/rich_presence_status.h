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

#ifndef _RICH_PRESENCE_STATUS_H_
#define _RICH_PRESENCE_STATUS_H_

#include "config_discord.h"
#include "discord_rpc.h"
#include "typedReferenceCount.h"

#include <string>
#include <iostream>

/*
 * Panda wrapper class for the discord-rpc DiscordRichPresence struct
 */
class RichPresenceStatus : public TypedReferenceCount {

    public:
        const struct DiscordRichPresence build_rich_presence();

        INLINE void set_state(const std::string state);
        INLINE std::string get_state();

        INLINE void set_details(const std::string details);
        INLINE std::string get_details();

        INLINE void set_start_timestamp(int64_t startTimestamp);
        INLINE int64_t get_start_timestamp();

        INLINE void set_end_timestamp(int64_t endTimestamp);
        INLINE int64_t get_end_timestamp();

        INLINE void set_large_image_key(const std::string largeImageKey);
        INLINE std::string get_large_image_key();

        INLINE void set_large_image_text(const std::string largeImageText);
        INLINE std::string get_large_image_text();

        INLINE void set_small_image_key(const std::string smallImageKey);
        INLINE std::string get_small_image_key();

        INLINE void set_small_image_text(const std::string smallImageText);
        INLINE std::string get_small_image_text();

        INLINE void set_party_id(const std::string partyId);
        INLINE std::string get_party_id();

        INLINE void set_party_size(int partySize);
        INLINE int get_party_size();

        INLINE void set_party_max(int partyMax);
        INLINE int get_party_max();

        INLINE void set_match_secret(const std::string matchSecret);
        INLINE std::string get_match_secret();

        INLINE void set_join_secret(const std::string joinSecret);
        INLINE std::string get_join_secret();

        INLINE void set_spectate_secret(const std::string spectateSecret);
        INLINE std::string get_spectate_secret();

        INLINE void set_instance(int8_t instance);
        INLINE int8_t get_instance();

    PUBLISHED:

        MAKE_PROPERTY(state, get_state, set_state);
        MAKE_PROPERTY(details, get_details, set_details);
        MAKE_PROPERTY(start_timestamp, get_start_timestamp, set_start_timestamp);
        MAKE_PROPERTY(end_timestamp, get_end_timestamp, set_end_timestamp);
        MAKE_PROPERTY(large_image_key, get_large_image_key, set_large_image_key);
        MAKE_PROPERTY(large_image_text, get_large_image_text, set_large_image_text);
        MAKE_PROPERTY(small_image_key, get_small_image_key, set_small_image_key);
        MAKE_PROPERTY(small_image_text, get_small_image_text, set_small_image_text);
        MAKE_PROPERTY(party_id, get_party_id, set_party_id);
        MAKE_PROPERTY(party_size, get_party_size, set_party_size);
        MAKE_PROPERTY(party_max, get_party_max, set_party_max);
        MAKE_PROPERTY(match_secret, get_match_secret, set_match_secret);
        MAKE_PROPERTY(join_secret, get_join_secret, set_join_secret);
        MAKE_PROPERTY(spectate_secret, get_spectate_secret, set_spectate_secret);
        MAKE_PROPERTY(instance, get_instance, set_instance);

    protected:
        std::string state;
        std::string details;

        int64_t startTimestamp;
        int64_t endTimestamp;

        std::string largeImageKey;
        std::string largeImageText;
        std::string smallImageKey;
        std::string smallImageText;

        std::string partyId;
        int partySize;
        int partyMax;

        std::string matchSecret;
        std::string joinSecret;
        std::string spectateSecret;

        int8_t instance;
    public:
        static TypeHandle get_class_type() {
            return _type_handle;
        }
        static void init_type() {
            TypedReferenceCount::init_type();
            register_type(_type_handle, "RichPresenceStatus",
                TypedReferenceCount::get_class_type());
        }
        virtual TypeHandle get_type() const {
            return get_class_type();
        }
        virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

    private:
        static TypeHandle _type_handle;
};
#include "rich_presence_status.I"

#endif