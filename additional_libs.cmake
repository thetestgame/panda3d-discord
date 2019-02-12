# Author: Jordan Maxwell
# Written: 02/08/2019
#
# The MIT License (MIT)
# 
# Copyright (c) 2019 Nxt Games
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is furnished to do
# so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Include Discord RPC library
set(DISCORD_RPC_ROOT ${PROJECT_SOURCE_DIR}/discord-rpc CACHE PATH "" FORCE)

if ((NOT EXISTS ${DISCORD_RPC_ROOT}))
    message(ERROR "Failed to build Panda3D LibDiscord; Discord RPC not found (${DISCORD_RPC_ROOT})")
endif()
message(STATUS "Found discord-rpc library: ${DISCORD_RPC_ROOT}")

# Link code
if (WIN32)
    link_libraries(${DISCORD_RPC_ROOT}/lib/discord-rpc.lib)
else()
    message(ERROR "Your platform is not supported by this CMake script")
endif()

include_directories(${DISCORD_RPC_ROOT}/include)