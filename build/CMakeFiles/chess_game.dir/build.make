# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/damian/Desktop/projects/chess_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/damian/Desktop/projects/chess_game/build

# Include any dependencies generated for this target.
include CMakeFiles/chess_game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chess_game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chess_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess_game.dir/flags.make

CMakeFiles/chess_game.dir/main.cpp.o: CMakeFiles/chess_game.dir/flags.make
CMakeFiles/chess_game.dir/main.cpp.o: /home/damian/Desktop/projects/chess_game/main.cpp
CMakeFiles/chess_game.dir/main.cpp.o: CMakeFiles/chess_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/damian/Desktop/projects/chess_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess_game.dir/main.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess_game.dir/main.cpp.o -MF CMakeFiles/chess_game.dir/main.cpp.o.d -o CMakeFiles/chess_game.dir/main.cpp.o -c /home/damian/Desktop/projects/chess_game/main.cpp

CMakeFiles/chess_game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess_game.dir/main.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damian/Desktop/projects/chess_game/main.cpp > CMakeFiles/chess_game.dir/main.cpp.i

CMakeFiles/chess_game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess_game.dir/main.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damian/Desktop/projects/chess_game/main.cpp -o CMakeFiles/chess_game.dir/main.cpp.s

# Object files for target chess_game
chess_game_OBJECTS = \
"CMakeFiles/chess_game.dir/main.cpp.o"

# External object files for target chess_game
chess_game_EXTERNAL_OBJECTS =

chess_game: CMakeFiles/chess_game.dir/main.cpp.o
chess_game: CMakeFiles/chess_game.dir/build.make
chess_game: CMakeFiles/chess_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/damian/Desktop/projects/chess_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chess_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chess_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess_game.dir/build: chess_game
.PHONY : CMakeFiles/chess_game.dir/build

CMakeFiles/chess_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chess_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chess_game.dir/clean

CMakeFiles/chess_game.dir/depend:
	cd /home/damian/Desktop/projects/chess_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/damian/Desktop/projects/chess_game /home/damian/Desktop/projects/chess_game /home/damian/Desktop/projects/chess_game/build /home/damian/Desktop/projects/chess_game/build /home/damian/Desktop/projects/chess_game/build/CMakeFiles/chess_game.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/chess_game.dir/depend

