# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/compsci260p/projects/proj0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/compsci260p/projects/proj0/out

# Include any dependencies generated for this target.
include CMakeFiles/a.out.gtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.out.gtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.out.gtest.dir/flags.make

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o: ../gtest/gtestmain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/compsci260p/projects/proj0/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o -c /home/compsci260p/projects/proj0/gtest/gtestmain.cpp

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/compsci260p/projects/proj0/gtest/gtestmain.cpp > CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/compsci260p/projects/proj0/gtest/gtestmain.cpp -o CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.requires:

.PHONY : CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.requires

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.provides: CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.gtest.dir/build.make CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.provides

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.provides.build: CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o


CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o: ../gtest/proj0test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/compsci260p/projects/proj0/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o -c /home/compsci260p/projects/proj0/gtest/proj0test.cpp

CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/compsci260p/projects/proj0/gtest/proj0test.cpp > CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/compsci260p/projects/proj0/gtest/proj0test.cpp -o CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o.requires:

.PHONY : CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o.requires

CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o.provides: CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.gtest.dir/build.make CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o.provides

CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o.provides.build: CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o


CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o: ../app/proj0.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/compsci260p/projects/proj0/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o -c /home/compsci260p/projects/proj0/app/proj0.cpp

CMakeFiles/a.out.gtest.dir/app/proj0.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/app/proj0.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/compsci260p/projects/proj0/app/proj0.cpp > CMakeFiles/a.out.gtest.dir/app/proj0.cpp.i

CMakeFiles/a.out.gtest.dir/app/proj0.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/app/proj0.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/compsci260p/projects/proj0/app/proj0.cpp -o CMakeFiles/a.out.gtest.dir/app/proj0.cpp.s

CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o.requires:

.PHONY : CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o.requires

CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o.provides: CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.gtest.dir/build.make CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o.provides

CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o.provides.build: CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o


# Object files for target a.out.gtest
a_out_gtest_OBJECTS = \
"CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o" \
"CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o"

# External object files for target a.out.gtest
a_out_gtest_EXTERNAL_OBJECTS =

bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/build.make
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/compsci260p/projects/proj0/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bin/a.out.gtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.out.gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.out.gtest.dir/build: bin/a.out.gtest

.PHONY : CMakeFiles/a.out.gtest.dir/build

CMakeFiles/a.out.gtest.dir/requires: CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.requires
CMakeFiles/a.out.gtest.dir/requires: CMakeFiles/a.out.gtest.dir/gtest/proj0test.cpp.o.requires
CMakeFiles/a.out.gtest.dir/requires: CMakeFiles/a.out.gtest.dir/app/proj0.cpp.o.requires

.PHONY : CMakeFiles/a.out.gtest.dir/requires

CMakeFiles/a.out.gtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out.gtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out.gtest.dir/clean

CMakeFiles/a.out.gtest.dir/depend:
	cd /home/compsci260p/projects/proj0/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/compsci260p/projects/proj0 /home/compsci260p/projects/proj0 /home/compsci260p/projects/proj0/out /home/compsci260p/projects/proj0/out /home/compsci260p/projects/proj0/out/CMakeFiles/a.out.gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out.gtest.dir/depend

