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
include src/bench/CMakeFiles/VDSProject_bench.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/bench/CMakeFiles/VDSProject_bench.dir/compiler_depend.make

# Include the progress variables for this target.
include src/bench/CMakeFiles/VDSProject_bench.dir/progress.make

# Include the compile flags for this target's objects.
include src/bench/CMakeFiles/VDSProject_bench.dir/flags.make

src/bench/CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o: src/bench/CMakeFiles/VDSProject_bench.dir/flags.make
src/bench/CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o: /VDSProject_Group2/src/bench/main_bench.cpp
src/bench/CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o: src/bench/CMakeFiles/VDSProject_bench.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/bench/CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o"
	cd /VDSProject_Group2/build/src/bench && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/bench/CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o -MF CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o.d -o CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o -c /VDSProject_Group2/src/bench/main_bench.cpp

src/bench/CMakeFiles/VDSProject_bench.dir/main_bench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VDSProject_bench.dir/main_bench.cpp.i"
	cd /VDSProject_Group2/build/src/bench && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /VDSProject_Group2/src/bench/main_bench.cpp > CMakeFiles/VDSProject_bench.dir/main_bench.cpp.i

src/bench/CMakeFiles/VDSProject_bench.dir/main_bench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VDSProject_bench.dir/main_bench.cpp.s"
	cd /VDSProject_Group2/build/src/bench && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /VDSProject_Group2/src/bench/main_bench.cpp -o CMakeFiles/VDSProject_bench.dir/main_bench.cpp.s

# Object files for target VDSProject_bench
VDSProject_bench_OBJECTS = \
"CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o"

# External object files for target VDSProject_bench
VDSProject_bench_EXTERNAL_OBJECTS =

src/bench/VDSProject_bench: src/bench/CMakeFiles/VDSProject_bench.dir/main_bench.cpp.o
src/bench/VDSProject_bench: src/bench/CMakeFiles/VDSProject_bench.dir/build.make
src/bench/VDSProject_bench: src/libManager.a
src/bench/VDSProject_bench: src/bench/libBenchmark.a
src/bench/VDSProject_bench: src/bench/CMakeFiles/VDSProject_bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VDSProject_bench"
	cd /VDSProject_Group2/build/src/bench && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VDSProject_bench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/bench/CMakeFiles/VDSProject_bench.dir/build: src/bench/VDSProject_bench
.PHONY : src/bench/CMakeFiles/VDSProject_bench.dir/build

src/bench/CMakeFiles/VDSProject_bench.dir/clean:
	cd /VDSProject_Group2/build/src/bench && $(CMAKE_COMMAND) -P CMakeFiles/VDSProject_bench.dir/cmake_clean.cmake
.PHONY : src/bench/CMakeFiles/VDSProject_bench.dir/clean

src/bench/CMakeFiles/VDSProject_bench.dir/depend:
	cd /VDSProject_Group2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /VDSProject_Group2 /VDSProject_Group2/src/bench /VDSProject_Group2/build /VDSProject_Group2/build/src/bench /VDSProject_Group2/build/src/bench/CMakeFiles/VDSProject_bench.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/bench/CMakeFiles/VDSProject_bench.dir/depend

