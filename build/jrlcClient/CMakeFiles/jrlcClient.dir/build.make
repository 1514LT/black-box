# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lt/workspace/black-box/TCP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lt/workspace/black-box/TCP/build

# Include any dependencies generated for this target.
include jrlcClient/CMakeFiles/jrlcClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include jrlcClient/CMakeFiles/jrlcClient.dir/compiler_depend.make

# Include the progress variables for this target.
include jrlcClient/CMakeFiles/jrlcClient.dir/progress.make

# Include the compile flags for this target's objects.
include jrlcClient/CMakeFiles/jrlcClient.dir/flags.make

jrlcClient/CMakeFiles/jrlcClient.dir/TCPClient.cpp.o: jrlcClient/CMakeFiles/jrlcClient.dir/flags.make
jrlcClient/CMakeFiles/jrlcClient.dir/TCPClient.cpp.o: ../jrlcClient/TCPClient.cpp
jrlcClient/CMakeFiles/jrlcClient.dir/TCPClient.cpp.o: jrlcClient/CMakeFiles/jrlcClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lt/workspace/black-box/TCP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object jrlcClient/CMakeFiles/jrlcClient.dir/TCPClient.cpp.o"
	cd /home/lt/workspace/black-box/TCP/build/jrlcClient && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT jrlcClient/CMakeFiles/jrlcClient.dir/TCPClient.cpp.o -MF CMakeFiles/jrlcClient.dir/TCPClient.cpp.o.d -o CMakeFiles/jrlcClient.dir/TCPClient.cpp.o -c /home/lt/workspace/black-box/TCP/jrlcClient/TCPClient.cpp

jrlcClient/CMakeFiles/jrlcClient.dir/TCPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jrlcClient.dir/TCPClient.cpp.i"
	cd /home/lt/workspace/black-box/TCP/build/jrlcClient && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lt/workspace/black-box/TCP/jrlcClient/TCPClient.cpp > CMakeFiles/jrlcClient.dir/TCPClient.cpp.i

jrlcClient/CMakeFiles/jrlcClient.dir/TCPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jrlcClient.dir/TCPClient.cpp.s"
	cd /home/lt/workspace/black-box/TCP/build/jrlcClient && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lt/workspace/black-box/TCP/jrlcClient/TCPClient.cpp -o CMakeFiles/jrlcClient.dir/TCPClient.cpp.s

# Object files for target jrlcClient
jrlcClient_OBJECTS = \
"CMakeFiles/jrlcClient.dir/TCPClient.cpp.o"

# External object files for target jrlcClient
jrlcClient_EXTERNAL_OBJECTS =

jrlcClient/jrlcClient: jrlcClient/CMakeFiles/jrlcClient.dir/TCPClient.cpp.o
jrlcClient/jrlcClient: jrlcClient/CMakeFiles/jrlcClient.dir/build.make
jrlcClient/jrlcClient: jrlcClient/CMakeFiles/jrlcClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lt/workspace/black-box/TCP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable jrlcClient"
	cd /home/lt/workspace/black-box/TCP/build/jrlcClient && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jrlcClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
jrlcClient/CMakeFiles/jrlcClient.dir/build: jrlcClient/jrlcClient
.PHONY : jrlcClient/CMakeFiles/jrlcClient.dir/build

jrlcClient/CMakeFiles/jrlcClient.dir/clean:
	cd /home/lt/workspace/black-box/TCP/build/jrlcClient && $(CMAKE_COMMAND) -P CMakeFiles/jrlcClient.dir/cmake_clean.cmake
.PHONY : jrlcClient/CMakeFiles/jrlcClient.dir/clean

jrlcClient/CMakeFiles/jrlcClient.dir/depend:
	cd /home/lt/workspace/black-box/TCP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lt/workspace/black-box/TCP /home/lt/workspace/black-box/TCP/jrlcClient /home/lt/workspace/black-box/TCP/build /home/lt/workspace/black-box/TCP/build/jrlcClient /home/lt/workspace/black-box/TCP/build/jrlcClient/CMakeFiles/jrlcClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : jrlcClient/CMakeFiles/jrlcClient.dir/depend

