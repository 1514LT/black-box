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
CMAKE_SOURCE_DIR = /home/lt/workspace/black-box/TCP/jrlcServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lt/workspace/black-box/TCP/jrlcServer/build

# Include any dependencies generated for this target.
include CMakeFiles/jrlcServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/jrlcServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/jrlcServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jrlcServer.dir/flags.make

CMakeFiles/jrlcServer.dir/TCPServer.cpp.o: CMakeFiles/jrlcServer.dir/flags.make
CMakeFiles/jrlcServer.dir/TCPServer.cpp.o: ../TCPServer.cpp
CMakeFiles/jrlcServer.dir/TCPServer.cpp.o: CMakeFiles/jrlcServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lt/workspace/black-box/TCP/jrlcServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/jrlcServer.dir/TCPServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/jrlcServer.dir/TCPServer.cpp.o -MF CMakeFiles/jrlcServer.dir/TCPServer.cpp.o.d -o CMakeFiles/jrlcServer.dir/TCPServer.cpp.o -c /home/lt/workspace/black-box/TCP/jrlcServer/TCPServer.cpp

CMakeFiles/jrlcServer.dir/TCPServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jrlcServer.dir/TCPServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lt/workspace/black-box/TCP/jrlcServer/TCPServer.cpp > CMakeFiles/jrlcServer.dir/TCPServer.cpp.i

CMakeFiles/jrlcServer.dir/TCPServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jrlcServer.dir/TCPServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lt/workspace/black-box/TCP/jrlcServer/TCPServer.cpp -o CMakeFiles/jrlcServer.dir/TCPServer.cpp.s

# Object files for target jrlcServer
jrlcServer_OBJECTS = \
"CMakeFiles/jrlcServer.dir/TCPServer.cpp.o"

# External object files for target jrlcServer
jrlcServer_EXTERNAL_OBJECTS =

jrlcServer: CMakeFiles/jrlcServer.dir/TCPServer.cpp.o
jrlcServer: CMakeFiles/jrlcServer.dir/build.make
jrlcServer: CMakeFiles/jrlcServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lt/workspace/black-box/TCP/jrlcServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable jrlcServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jrlcServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jrlcServer.dir/build: jrlcServer
.PHONY : CMakeFiles/jrlcServer.dir/build

CMakeFiles/jrlcServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jrlcServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jrlcServer.dir/clean

CMakeFiles/jrlcServer.dir/depend:
	cd /home/lt/workspace/black-box/TCP/jrlcServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lt/workspace/black-box/TCP/jrlcServer /home/lt/workspace/black-box/TCP/jrlcServer /home/lt/workspace/black-box/TCP/jrlcServer/build /home/lt/workspace/black-box/TCP/jrlcServer/build /home/lt/workspace/black-box/TCP/jrlcServer/build/CMakeFiles/jrlcServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jrlcServer.dir/depend

