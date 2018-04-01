# MSYS2
MSYS2's pacman allows to download MinGW-W64.
- www.msys2.org, msys2-x86_64-yyyymmdd.exe
- ref: github.com/msys2/msys2/wiki/MSYS2-installation
- run msys2-x86-yyyymmdd.exe
- Installation Folder: C:\msys64
- open MSYS2 Shell, repeat this step until it says no more packages to update
```
    $ pacman -Syuu
```
- install utilities
  - compression: zip/unzip, 7zip
  - editors: emacs, nano, vim
```
    $ pacman -S compression editors
```
# MinGW-W64
The Gnu C++ toolchain for Windows.
- ref: github.com/orlp/dev-on-windows/wiki/Installing-GCC--&-MSYS2
- install MinGW-W64
  - base-devel: make
  - mingw-w64-xxxxx-toolchain: gcc & gdb
```
    $ pacman -S --needed base-devel mingw-w64-i686-toolchain mingw-w64-x86_64-toolchain
```
- set PATH so that you can use MinGW-W64 from Windows command prompt
```
    MINGW32=C:\msys64\mingw32
    MINGW64=C:\msys64\mingw64
    MINGW=%MINGW32% (or %MINGW64%)
    PATH=%PATH%;C:\msys64\usr\bin;%MINGW%\bin
```
- check the version of tools
```
    > g++ -v
    > gdb -v
```
- build a C++17 application
```
    > cd %USERPROFILE%\cpp\hello
    > type HelloFilesystem.cpp
    #include <iostream>
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
    using namespace std;
    int main() {
      cout << fs::current_path() << endl;
      return 0;
    }

    > g++ -std=c++17 HelloFilesystem.cpp -lstdc++fs
    > a.exe
    C:\\Users\\yourID\\cpp\\hello
```
- find the include path, the library path, the compiler and linker options
```
    > gcc -v -E -x c++ -
    COLLECT_GCC_OPTIONS='-std=c++1z' '-shared-libgcc' '-mtune=generic' '-march=i686'
    #include <...> search starts here:
     C:/msys64/mingw32/include/c++/7.3.0
     C:/msys64/mingw32/include/c++/7.3.0/i686-w64-mingw32
     C:/msys64/mingw32/include/c++/7.3.0/backward
     C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include
     C:/msys64/mingw32/include
     C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include-fixed
     C:/msys64/mingw32/i686-w64-mingw32/include
```

# wxWidgets
The cross-platform GUI library.
- download the source code
  - www.wxwidgets.org/downloads/
  - Version 3.0.4, Windows 7Z
- unpack the .7z file into /c/wx/wx304
```
    $ mkdir /c/wx
    $ mkdir /c/wx/wx304
    $ 7za x /c/$USERNAME/Downloads/wxWidgets-3.0.4.7z -o/c/wx/wx304
```
- building 32-bit DEBUG library at /c/wx/wx304/buid32-debug
  - ref: /c/wx/wx304/docs/msw/install.txt
  - open MSYS2 MinGW 32-bit shell, then
```
    $ cd /c/wx/wx304
    $ mkdir build32-debug
    $ cd build32-debug
    $ ../configure --disable-shared --enable-debug
    $ make
    $ cd samples/minimal
    $ make
    $ ./minimal.exe
```
- building 32-bit RELEASE library at /c/wx/wx304/buid32-release
  - open MSYS2 MinGW 32-bit shell, then
```
    $ cd /c/wx/wx304
    $ mkdir build32-release
    $ cd build32-release
    $ ../configure --disable-shared
    $ make
    $ cd samples/minimal
    $ make
    $ ./minimal.exe
```
- here are compile & link options used by samples/minimal
<table>
    <tr>
        <th>Tool</th>
        <th>Option</th>
        <th>Debug</th>
        <th>Release</th>
    </tr>
    <tr>
        <td rowspan="3">windres</td>
        <td>--define</td>
        <td colspan="2">__WXMSW__</td>
    </tr>
    <tr>
        <td rowspan="2">--include-dir</td>
        <td colspan="2">/c/wx/wx304/include</td>
    </tr>
    <tr>
        <td>/c/wx/wx304/build32-debug/lib/wx/include/msw-unicode-static-3.0</td>
        <td>/c/wx/wx304/build32-release/lib/wx/include/msw-unicode-static-3.0</td>
    </tr>
    <tr>
        <td rowspan="5">g++ -c</td>
        <td>-D</td>
        <td colspan="2">-D__WXMSW__ -D_FILE_OFFSET_BITS=64 -DWX_PRECOMP</td>
    </tr>
    <tr>
        <td rowspan="2">-I</td>
        <td colspan="2">/c/wx/wx304/include</td>
    </tr>
    <tr>
        <td>/c/wx/wx304/build32-debug/lib/wx/include/msw-unicode-static-3.0</td>
        <td>/c/wx/wx304/build32-release/lib/wx/include/msw-unicode-static-3.0</td>
    </tr>
    <tr>
        <td>-W</td>
        <td colspan="2">-Wall -Wundef -Wunused-parameter -Wno-ctor-dtor-privacy -Woverloaded-virtual</td>
    </tr>
    <tr>
        <td>others</td>
        <td>-mthreads -g -O0</td>
        <td>-mthreads -O2 -fno-strict-aliasing</td>
    </tr>
    <tr>
        <td rowspan="3">g++ -o a.exe</td>
        <td>-L</td>
        <td>/c/wx/wx304/build32-debug/lib</td>
        <td>/c/wx/wx304/build32-release/lib</td>
    </tr>
    <tr>
        <td>-l</td>
        <td colspan="2">
  -lwx_mswu_core-3.0  -lwx_baseu-3.0
  -lwxtiff-3.0 -lwxjpeg-3.0 -lwxpng-3.0 -lwxregexu-3.0
  -lz -lrpcrt4 -loleaut32 -lole32 -luuid -llzma -lwinspool -lwinmm
  -lshell32 -lcomctl32 -lcomdlg32 -ladvapi32 -lwsock32 -lgdi32
        </td>
    </tr>
    <tr>
        <td>others</td>
        <td colspan="2">-mwindows  -mthreads</td>
    </tr>
</table>

# Git
- git-scm.com/download
- Git-2.16.2-64-bit.exe
- install Git into C:\Program Files\Git
- open Git Bash shell to check the installation
```
    $ git --version
```
- configure Git
  - ref: git-scm.com/book/en/v2/Getting-Started-First-Time-Git-Setup
  - open Git Bash shell
```
    $ git config --global user.name "your name"
    $ git config --global user.email your.account@mail.somewhere
    $ git config --global core.editor of_your_choise (e.g. "C:/msys64/usr/bin/vim.exe")
    $ git config --list
```
- generate your SSH public key
  - ref: git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key
  - open Git Bash shell
```
    $ cd ~/.ssh
    $ ssh-keygen
    Generating public/private rsa key pair.
    Enter file in which to save the key (/c/Users/yourID/.ssh/id_rsa): <<depress Enter>>
    Enter passphrase (empty for no passphrase): <<your passphrase>>
    Enter same passphrase again: <<your passphrase>>
    Your identification has been saved in /c/Users/yourID/.ssh/id_rsa.
    Your public key has been saved in /c/Users/yourID/.ssh/id_rsa.pub.
```
- register the public key in your github.com account

# VS Code
One of the IDE that works on macOS, Linux and Windows.
- code.visualstudio.com
- install and customize it as you wish

# VS Code integration with Git
Cloning a github.com repository.
- ref: code.visualstudio.com/docs/editor/versioncontrol
- at github.com
  - create a reposiotry, e.g. wxWidgets, in your account of github.com.
  - create and commit README.md in the repository.
- on your Windows
  - create a folder, e.g. %USERPROFILE%\workspace-vscode
- clone the repository with the Git: Clone command in the Command Pallete
  - from: your repository, e.g. github.com/your-account/your-repo
  - to: your local folder, e.g. %USERPROFILE%\workspace-vscode
- you will get the clone repository
  - %USERPROFILE%\workspace-vscode\your-repo
  - create the '.gitignore' file in your-repo
```
    *.o
    *.exe
```
- don't let the Git extension to open the repo, just close the Git extension popup

Making the repo as a VS Code workspace.
- create the root-workspace folder
  - e.g. the 'vscode' folder in %USERPROFILE%\workspace-vscode\your-repo
  - the shared settings among multiple workspaces under the folder will go there
- now is the time you can customize VS Code settings
  - click the Cog icon at the bottom of the Explorer
  - you can customize two types of settings
    - User Setting
    - Workspace Settings
  - for example, customize the User Settings as follows
```
{
    "editor.tabSize": 2,
    "terminal.integrated.shell.windows": "C:\\Windows\\System32\\cmd.exe",
    "git.confirmSync": false
}
```
- save the workspace configuration file
  - File > Save As Workspace...
  - save as, e.g. 'your-repo.code-workspace' file in the your-repo folder
```
    {
      "folders": [
        {
          "path": "vscode"
        }
      ],
      "settings": {}
    }
```
- check to see if Git is working
  - in the Exploere view, the following should be marked as an untracked change
    - your-repo\vscode\.vscode\settings.json
  - in the Source Control view, the following should be marked as untracked changes
    - your-repo\vscode\.vscode\settings.json
    - your-repo\your-repo.code-workspace
    - your-repo\.gitignorefile
  - add the above files into the Git index, then
    - commit
    - synchronize changes
  - check github.com to see if the file is synchronized

# VS Code integration with MinGW-W64
Configuring VS Code to work with MinGW-W64 toolchain.
- Ref: github.com/Microsoft/vscode-cpptools/blob/master/Documentation/LanguageServer/MinGW.md
- install the C/C++ for Visual Studio Code extension (ms-vscode.cpptools)
- create c_cpp_properties.json with C/Cpp: Edit Configuration command in the Command Pallete
```
{
  "configurations": [
    {
      "name": "Mac",
      as is ...
    },
    {
      "name": "Linux",
      as is ...
    },
    {
      "name": "Win32",
      "includePath": [
        "${workspaceRoot}",
        "C:/msys64/mingw32/include/c++/7.3.0",
        "C:/msys64/mingw32/include/c++/7.3.0/i686-w64-mingw32",
        "C:/msys64/mingw32/include/c++/7.3.0/backward",
        "C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include",
        "C:/msys64/mingw32/include",
        "C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include-fixed",
        "C:/msys64/mingw32/i686-w64-mingw32/include"
      ],
      "defines": [
        "_DEBUG",
        "UNICODE",
        "__GNUC__=7",
        "__cdecl=__attribute__((__cdecl__))"
      ],
      "intelliSenseMode": "clang-x64",
      "browse": {
        "path": [
          "${workspaceRoot}",
          "C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include",
          "C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include-fixed",
          "C:/msys64/mingw32/include/*"
        ],
        "limitSymbolsToIncludedHeaders": true,
        "databaseFilename": ""
      },
      "cppStandard": "c++17",
      "cStandard": "c11"
    }
  ],
  "version": 3
}
```
- create the 'hello' folder in the workspace
  - ref: code.visualstudio.com/docs/editor/multi-root-workspaces
  - File > Add Folder to Workspace
  - select %USERPROFILE%/workspace-vscode/your-repo
  - create a folder in the your-repo and name it 'hello'
  - select the hello folder to add to the workspace
  - your workspace now has two folders: vscode and hello
  - the Explorer should look like this
```
    > YOUR-REPO (WORKSPACE)
      > vscode
        > .vscode
          {} c_cpp_properties.json
          {} settings.json
      > hello
```
- copy vscode\.vscode\c_cpp_properties.json into the hello folder
  - the Explorer should look like this
```
    > YOUR-REPO (WORKSPACE)
      > vscode
        > .vscode
          {} c_cpp_properties.json
          {} settings.json
      > hello
        > .vscode
          {} c_cpp_properties.json
```
- create tasks.json in the hello folder
  - Tasks > Configure Tasks menu
  - you should have two options
    - Create task.json file from template - your-repo
    - Create task.json file from template - hello
  - select 'Create ... - hello'
```
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "make hello",
      "type": "shell",
      "command": "make",
      "problemMatcher": [],
      "group": "build",
      "presentation": {
        "echo": true,
        "reveal": "always",
        "focus": false,
        "panel": "shared"
      }
    },
    {
      "label": "clean hello",
      "type": "shell",
      "command": "make clean",
      "problemMatcher": [],
      "group": "build",
      "presentation": {
        "echo": true,
        "reveal": "always",
        "focus": false,
        "panel": "shared"
      }
    }
  ]
}
```
- compile a plain C++ program with VS Code
  - put helloFilesystem.cpp in the hello folder
  - create Makefile in the hello folder 
  - and Tasks > Run Tasks... > 'make hello'
  - make sure that *.o and *.exe are git-ignored 
```
CFLAGS=-g -std=c++1z -static -mtune=generic -march=i686
INCLUDES=
LDFLAGS=
LIBS=-lstdc++fs

helloFilesystem.exe: helloFilesystem.o
	$(CXX) $(INCLUDES) $? $(LDFLAGS) -o $@ $(LIBS)

clean:
	rm *.o helloFilesystem.exe

.cpp.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $<
```
- create launch.json to enable debugging
  - ref: code.visualstudio.com/docs/languages/cpp
  - open the Debug view, and click the 'No Configuration' popup at the top
  - you will find three options in the dropdown menu
    - Add Config (your-repo)
    - Add Config (hello)
    - Add Config (workspace)
  - select the Add Config (hello) option
  - select C++ (GDB/LLDB) (to use GDB)
  - update the lanuch.json template as follows
  - you can debug helloFilesystem by starting '(gdb) Lanuch hello' from the Debug view
  - don't forget to add breakpoints before starting debugging
```
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(gdb) Launch hello",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/helloFilesystem.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": true,
      "MIMode": "gdb",
      "miDebuggerPath": "C:\\msys64\\mingw32\\bin\\gdb.exe",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "make hello"
    }
  ]
}
```

# VS Code integratiion with MinGW-W64 and wxWidgets library
Configuring VS Code to work with wxWidgets applications
- create a folder for a wxWidgets application, say helloWidgets
  - %USERPROFILE%/workspace-vscode/widgets/helloWidegts
- add the folder to the VS Code workspace widgets.code-workspace
  - select the Widgets workspace in the Explorer view
  - File > Add Folder to Workspace
  - select the helloWidegts folder to add
- create c_cpp_properties.json in the helloWidgets folder
  - create the .vscode folder in the helloWidgets folder
  - copy ../hello/.vscode/c_cpp_properties.json into the new .vscode folder
  - edit the new c_cpp_properties.json as follows:
```
{
  "configurations": [
    {
      "name": "Mac",
      as is ...
    },
    {
      "name": "Linux",
      as is ...
    },
    {
      "name": "Win32",
      "includePath": [
        "${workspaceRoot}",
        "C:/msys64/mingw32/include/c++/7.3.0",
        "C:/msys64/mingw32/include/c++/7.3.0/i686-w64-mingw32",
        "C:/msys64/mingw32/include/c++/7.3.0/backward",
        "C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include",
        "C:/msys64/mingw32/include",
        "C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include-fixed",
        "C:/msys64/mingw32/i686-w64-mingw32/include",
        "C:/wx/wx304/include",
        "C:/wx/wx304/build32-release/lib/wx/include/msw-unicode-static-3.0"
      ],
      "defines": [
        "_DEBUG",
        "UNICODE",
        "__GNUC__=7",
        "__cdecl=__attribute__((__cdecl__))",
        "__WXMSW__",
        "_FILE_OFFSET_BITS=64",
        "WX_PRECOMP"
      ],
      "intelliSenseMode": "clang-x64",
      "browse": {
        "path": [
          "${workspaceRoot}",
          "C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include",
          "C:/msys64/mingw32/lib/gcc/i686-w64-mingw32/7.3.0/include-fixed",
          "C:/msys64/mingw32/include/*"
        ],
        "limitSymbolsToIncludedHeaders": true,
        "databaseFilename": ""
      },
      "cppStandard": "c++17",
      "cStandard": "c11"
    }
  ],
  "version": 3
}
```
- prepare the json files based on those files in the hello folder
  - tasks.json
  - launch.json
- prepare Makefile
  - based on the Makefile in the hello folders
  - add compiler/linker options for wxWidgets
```
CFLAGS=-mthreads -g -O0 -std=c++1z -static -mtune=generic -march=i686 \
  -Wall -Wundef -Wunused-parameter -Wno-ctor-dtor-privacy -Woverloaded-virtual
INCLUDES=-I/c/wx/wx304/include -I/c/wx/wx304/build32-debug/lib/wx/include/msw-unicode-static-3.0
DEFINES=-D__WXMSW__ -D_FILE_OFFSET_BITS=64 -DWX_PRECOMP
LDFLAGS=-mwindows -mthreads
LIBS=-lstdc++fs -L/c/wx/wx304/build32-debug/lib \
  -lwx_mswu_core-3.0 -lwx_baseu-3.0 -lwxtiff-3.0 -lwxjpeg-3.0 -lwxpng-3.0 -lwxregexu-3.0 \
	-lz -lrpcrt4 -loleaut32 -lole32 -luuid -llzma -lwinspool -lwinmm -lshell32 -lcomctl32 \
	-lcomdlg32 -ladvapi32 -lwsock32 -lgdi32

helloWidgets.exe: helloWidgets.o
	$(CXX) $? $(LDFLAGS) -o $@ $(LIBS)

clean:
	rm *.o helloWidgets.exe

.cpp.o:
	$(CXX) $(CFLAGS) $(DEFINES) $(INCLUDES) -c $<
```
- create helloWidgets.cpp
  - a sample wxWidgets from docs.wxwidgets.org/trunk/overview_helloworld.html
- disable the Error Squiggles
  - open the helloWidgets.cpp, when you might find error squigles
  - you can safely ignore them by creating helloWidgets/.vscode/settings.json
```
{
  "C_Cpp.errorSquiggles": "Disabled"
}
```
- check if you can build helloWidgets.cpp
  - Tasks > Run Tasks.. > make helloWidgets