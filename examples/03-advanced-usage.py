"""
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
"""

# include built pyd file
import sys
sys.path.append('../')

from panda3d.core import ConfigVariableInt, ConfigVariableString, load_prc_file_data
from direct.showbase.ShowBase import ShowBase
from discord import DiscordConnection, RichPresenceStatus

# Set test status 
"""
status = RichPresenceStatus()
status.state = 'In Match'
status.details = 'Playing on Gold (4x4)'
status.large_image_key = 'map_gold'
status.large_image_text = 'Gold'
status.small_image_key = 'sm_droid'
status.small_image_text = 'Standard Droid'
status.party_size = 3
status.party_max = 4
status.join_secret = 'ExampleSecretTokenForJoinButton'
connection.publish_status(status)
"""

load_prc_file_data("", """
    window-title libDiscord - Advanced Usage
    discord-application-id 447876454454132737
    match-max-users 4
""")

class DiscordShowBase(ShowBase):
    """
    Custom Showbase for showcasing
    advanced usage of the libDiscord library
    """

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.accept('discord-ready', self.on_discord_ready)
        self.accept('discord-disconnect', self.on_discord_disconnect)
        self.userExit = self.showbase_shutdown

        self.application_id = ConfigVariableString('discord-application-id', '').value
        self.steam_id = ConfigVariableString('discord-steam-id', '').value
        self.connection = DiscordConnection.get_global_ptr()
        self.connection.connect(self.application_id, self.steam_id)

        self.max_users = ConfigVariableInt('match-max-users', 4).value
        self.current_users = 1

        self.taskMgr.add(self.update_discord_task, 'discord-update-task')

        self.accept('a', self.adjust_users, [1])
        self.accept('z', self.adjust_users, [-1])

    def showbase_shutdown(self):
        """
        Called on Panda shutdown
        """

        self.connection.disconnect()

    def update_discord_task(self, task):
        """
        Calls the connection update function once per frame.
        Performs connection maintenance and callbacks.
        """

        self.connection.poll()
        
        return task.cont  

    def on_discord_ready(self, connected_user):
        """
        Called when the Discord connection is established
        """

        print('Logged in as %s (%s) under application id: %s' % (
            connected_user.discord_tag, connected_user.user_id, self.application_id))

        self.publish_state()

    def on_discord_disconnect(self):
        """
        Called when the Discord connection is closed
        """

        print('Disconnected from Discord client')

    def publish_state(self):
        """
        Publishes the current game state to Discord
        """

        print('Publishing Discord status')

        status = RichPresenceStatus()
        status.state = 'In Match'
        status.details = 'Playing on Gold (4x4)'
        status.large_image_key = 'map_gold'
        status.large_image_text = 'Gold'
        status.small_image_key = 'sm_droid'
        status.small_image_text = 'Standard Droid'
        status.match_secret = 'ExampleSecretTokenForMatch'

        status.party_size = self.current_users
        status.party_max = self.max_users
        if self.current_users == self.max_users:
            status.spectate_secret = 'ExampleSecretTokenForSpectateButton'
        else:
            status.join_secret = 'ExampleSecretTokenForJoinButton'

        self.connection.publish_status(status)      

    def adjust_users(self, amount):
        """  
        Adjusts the current user count
        """

        self.current_users += amount
        if self.current_users < 0:
            self.current_users = 0

        if self.current_users > self.max_users:
            self.current_users = self.max_users

        self.publish_state()

base = DiscordShowBase()
base.run()