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
include CMakeFiles/benchmark.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/benchmark.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/benchmark.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/benchmark.dir/flags.make

CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o: /VDSProject_Group2/src/bench/main_bench.cpp
CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o: CMakeFiles/benchmark.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o -MF CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o.d -o CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o -c /VDSProject_Group2/src/bench/main_bench.cpp

CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /VDSProject_Group2/src/bench/main_bench.cpp > CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.i

CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /VDSProject_Group2/src/bench/main_bench.cpp -o CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.s

CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o: /VDSProject_Group2/src/bench/BenchmarkLib.cpp
CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o: CMakeFiles/benchmark.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o -MF CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o.d -o CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o -c /VDSProject_Group2/src/bench/BenchmarkLib.cpp

CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /VDSProject_Group2/src/bench/BenchmarkLib.cpp > CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.i

CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /VDSProject_Group2/src/bench/BenchmarkLib.cpp -o CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.s

CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o: /VDSProject_Group2/src/bench/BenchParser.cpp
CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o: CMakeFiles/benchmark.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o -MF CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o.d -o CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o -c /VDSProject_Group2/src/bench/BenchParser.cpp

CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /VDSProject_Group2/src/bench/BenchParser.cpp > CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.i

CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /VDSProject_Group2/src/bench/BenchParser.cpp -o CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.s

CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o: /VDSProject_Group2/src/bench/CircuitToBDD.cpp
CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o: CMakeFiles/benchmark.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o -MF CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o.d -o CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o -c /VDSProject_Group2/src/bench/CircuitToBDD.cpp

CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /VDSProject_Group2/src/bench/CircuitToBDD.cpp > CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.i

CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /VDSProject_Group2/src/bench/CircuitToBDD.cpp -o CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.s

CMakeFiles/benchmark.dir/src/Manager.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/Manager.cpp.o: /VDSProject_Group2/src/Manager.cpp
CMakeFiles/benchmark.dir/src/Manager.cpp.o: CMakeFiles/benchmark.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/benchmark.dir/src/Manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark.dir/src/Manager.cpp.o -MF CMakeFiles/benchmark.dir/src/Manager.cpp.o.d -o CMakeFiles/benchmark.dir/src/Manager.cpp.o -c /VDSProject_Group2/src/Manager.cpp

CMakeFiles/benchmark.dir/src/Manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/Manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /VDSProject_Group2/src/Manager.cpp > CMakeFiles/benchmark.dir/src/Manager.cpp.i

CMakeFiles/benchmark.dir/src/Manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/Manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /VDSProject_Group2/src/Manager.cpp -o CMakeFiles/benchmark.dir/src/Manager.cpp.s

# Object files for target benchmark
benchmark_OBJECTS = \
"CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o" \
"CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o" \
"CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o" \
"CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o" \
"CMakeFiles/benchmark.dir/src/Manager.cpp.o"

# External object files for target benchmark
benchmark_EXTERNAL_OBJECTS =

benchmark: CMakeFiles/benchmark.dir/src/bench/main_bench.cpp.o
benchmark: CMakeFiles/benchmark.dir/src/bench/BenchmarkLib.cpp.o
benchmark: CMakeFiles/benchmark.dir/src/bench/BenchParser.cpp.o
benchmark: CMakeFiles/benchmark.dir/src/bench/CircuitToBDD.cpp.o
benchmark: CMakeFiles/benchmark.dir/src/Manager.cpp.o
benchmark: CMakeFiles/benchmark.dir/build.make
benchmark: CMakeFiles/benchmark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/VDSProject_Group2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable benchmark"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/benchmark.dir/build: benchmark
.PHONY : CMakeFiles/benchmark.dir/build

CMakeFiles/benchmark.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/benchmark.dir/cmake_clean.cmake
.PHONY : CMakeFiles/benchmark.dir/clean

CMakeFiles/benchmark.dir/depend:
	cd /VDSProject_Group2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /VDSProject_Group2 /VDSProject_Group2 /VDSProject_Group2/build /VDSProject_Group2/build /VDSProject_Group2/build/CMakeFiles/benchmark.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/benchmark.dir/depend

