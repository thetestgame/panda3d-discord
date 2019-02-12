/**
 * Author: Jordan Maxwell
 * Written: 02/08/2019
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

#include "config_discord.h"

/*
 * Import all the required files for the libdiscord module
 */
#include "discord_connection_user.h"
#include "discord_connection.h"
#include "rich_presence_status.h"

#include "dconfig.h"

Configure(config_discord);
NotifyCategoryDef(discord , "");

ConfigureFn(config_discord) {
  init_libdiscord();
}

/**
 * Initializes the library.  This must be called at least once before any of
 * the functions or classes in this library can be used.  Normally it will be
 * called by the static initializers and need not be called explicitly, but
 * special cases exist.
 */
void init_libdiscord() {
  static bool initialized = false;
  if (initialized) {
    return;
  }
  initialized = true;

  DiscordConnectionUser::init_type();
  DiscordConnection::init_type();
  RichPresenceStatus::init_type();

}

