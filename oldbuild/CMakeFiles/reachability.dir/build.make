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
CMAKE_COMMAND = /snap/cmake/1364/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1364/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /VDSProject_Group2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /VDSProject_Group2/build

# Include any dependencies generated for this target.
include CMakeFiles/reachability.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/reachability.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/reachability.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reachability.dir/flags.make

CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o: CMakeFiles/reachability.dir/flags.make
CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o: /VDSProject_Group2/src/reachability/main_test.cpp
CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o: CMakeFiles/reachability.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o -MF CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o.d -o CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o -c /VDSProject_Group2/src/reachability/main_test.cpp

CMakeFiles/reachability.dir/src/reachability/main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reachability.dir/src/reachability/main_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /VDSProject_Group2/src/reachability/main_test.cpp > CMakeFiles/reachability.dir/src/reachability/main_test.cpp.i

CMakeFiles/reachability.dir/src/reachability/main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reachability.dir/src/reachability/main_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /VDSProject_Group2/src/reachability/main_test.cpp -o CMakeFiles/reachability.dir/src/reachability/main_test.cpp.s

# Object files for target reachability
reachability_OBJECTS = \
"CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o"

# External object files for target reachability
reachability_EXTERNAL_OBJECTS =

reachability: CMakeFiles/reachability.dir/src/reachability/main_test.cpp.o
reachability: CMakeFiles/reachability.dir/build.make
reachability: CMakeFiles/reachability.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable reachability"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reachability.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reachability.dir/build: reachability
.PHONY : CMakeFiles/reachability.dir/build

CMakeFiles/reachability.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reachability.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reachability.dir/clean

CMakeFiles/reachability.dir/depend:
	cd /VDSProject_Group2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /VDSProject_Group2 /VDSProject_Group2 /VDSProject_Group2/build /VDSProject_Group2/build /VDSProject_Group2/build/CMakeFiles/reachability.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/reachability.dir/depend

