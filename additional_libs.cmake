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

# Link code
target_link_libraries(${PROJECT_NAME} ${DISCORD_RPC_ROOT}/lib/discord-rpc.lib)
target_include_directories(${PROJECT_NAME} PRIVATE ${DISCORD_RPC_ROOT}/include)

# Copy library to output
if (WIN32) 
    add_custom_command(TARGET ${project_target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${DISCORD_RPC_ROOT}/bin/discord-rpc.dll"
        $<TARGET_FILE_DIR:${project_target}>)    
else()
    message(WARNING "This operating system is not supported by the Panda3D LibDiscord
     CMake.")
endif()