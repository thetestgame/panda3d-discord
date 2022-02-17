<img src="https://avatars3.githubusercontent.com/u/1965106?s=200&v=4" align="right">

Panda3d Discord
===============
![GitHub issues](https://img.shields.io/github/issues/NxtStudios/p3d-discord?style=for-the-badge)
![PyPI - Status](https://img.shields.io/pypi/status/panda3d_discord?style=for-the-badge)

<b>Notice:</b> The discord-rpc library is no longer under development. However an official response from Discord states the library will continue to function because it uses the same protocol as the new game sdk that Discord offers.

Discord RPC module for the Panda3d game engine using the native discord-rpc library. Currently the CMAKE code is only setup to operate properly on Windows. The source its self should have no issues running on other platforms however.


## Building Panda3D Discord
run `python build.py`. This will build the module for you're current platform once the required dependencies are installed/availble.

### Requirements

- The Panda3D SDK (get it <a href="http://www.panda3d.org/download.php?sdk">here</a>)
- CMake 2.6 or higher (get it <a href="https://cmake.org/download/">here</a>)
- windows only: The thirdparty folder installed in the Panda3D sdk folder (See <a href="https://www.panda3d.org/forums/viewtopic.php?f=9&t=18775">here</a>)
- discord-rpc (get it <a href="https://github.com/discordapp/discord-rpc">here</a>)

**For compiling on Windows 32 bit:**

- Visual Studio 2010/2015

**For compiling on Windows 64 bit:**

- Visual Studio 2010/2015
- Windows SDK 7.1 (be sure to tick the VC++ 64 bit compilers option)

## License
Panda3D Discord is licensed under the MIT license. See the provided LICENSE file for details.

