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

class RichPresenceStatus : public TypedReferenceCount, DiscordRichPresence {

    public:
        const struct DiscordRichPresence build_rich_presence();

    PUBLISHED:
        INLINE void set_state(const std::string state);
        INLINE std::string get_state();
        MAKE_PROPERTY(state, get_state, set_state);

        INLINE void set_details(const std::string details);
        INLINE std::string get_details();
        MAKE_PROPERTY(details, get_details, set_details);

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