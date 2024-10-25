1. Run the Program in path Robot\out\build\x64-debug\Robot\Robot.exe

2. I added an output of the command to confirm a valid command.
   For example, 

Start entering command:
don
asdfasdf -> invalid command, no succeeding display of command
report
REPORT   -> valid command, there is succeeding display of command
Output: 0, 0, NORTH
move
MOVE
REPORT
REPORT
Output: 0, 0, NORTH

3. This was compiled with CMAKE cmake version 3.29.5-msvc4 using Vistual Studio.
   This is using C++20 version as stated in https://cmake.org/cmake/help/latest/manual/cmake-cxxmodules.7.html#manual:cmake-cxxmodules(7)



