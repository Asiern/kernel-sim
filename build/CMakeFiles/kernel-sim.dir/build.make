# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/asier/kernel-sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/asier/kernel-sim/build

# Include any dependencies generated for this target.
include CMakeFiles/kernel-sim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/kernel-sim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/kernel-sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kernel-sim.dir/flags.make

CMakeFiles/kernel-sim.dir/src/main.c.o: CMakeFiles/kernel-sim.dir/flags.make
CMakeFiles/kernel-sim.dir/src/main.c.o: ../src/main.c
CMakeFiles/kernel-sim.dir/src/main.c.o: CMakeFiles/kernel-sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/asier/kernel-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/kernel-sim.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/kernel-sim.dir/src/main.c.o -MF CMakeFiles/kernel-sim.dir/src/main.c.o.d -o CMakeFiles/kernel-sim.dir/src/main.c.o -c /home/asier/kernel-sim/src/main.c

CMakeFiles/kernel-sim.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel-sim.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asier/kernel-sim/src/main.c > CMakeFiles/kernel-sim.dir/src/main.c.i

CMakeFiles/kernel-sim.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel-sim.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asier/kernel-sim/src/main.c -o CMakeFiles/kernel-sim.dir/src/main.c.s

# Object files for target kernel-sim
kernel__sim_OBJECTS = \
"CMakeFiles/kernel-sim.dir/src/main.c.o"

# External object files for target kernel-sim
kernel__sim_EXTERNAL_OBJECTS =

kernel-sim: CMakeFiles/kernel-sim.dir/src/main.c.o
kernel-sim: CMakeFiles/kernel-sim.dir/build.make
kernel-sim: CMakeFiles/kernel-sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/asier/kernel-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable kernel-sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kernel-sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kernel-sim.dir/build: kernel-sim
.PHONY : CMakeFiles/kernel-sim.dir/build

CMakeFiles/kernel-sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kernel-sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kernel-sim.dir/clean

CMakeFiles/kernel-sim.dir/depend:
	cd /home/asier/kernel-sim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/asier/kernel-sim /home/asier/kernel-sim /home/asier/kernel-sim/build /home/asier/kernel-sim/build /home/asier/kernel-sim/build/CMakeFiles/kernel-sim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kernel-sim.dir/depend

