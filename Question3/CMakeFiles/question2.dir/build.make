# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/haziq/Documents/algo2/Question2_Cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haziq/Documents/algo2/Question2_Cmake

# Include any dependencies generated for this target.
include CMakeFiles/question2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/question2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/question2.dir/flags.make

CMakeFiles/question2.dir/Main.cpp.o: CMakeFiles/question2.dir/flags.make
CMakeFiles/question2.dir/Main.cpp.o: Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haziq/Documents/algo2/Question2_Cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/question2.dir/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/question2.dir/Main.cpp.o -c /home/haziq/Documents/algo2/Question2_Cmake/Main.cpp

CMakeFiles/question2.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/question2.dir/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haziq/Documents/algo2/Question2_Cmake/Main.cpp > CMakeFiles/question2.dir/Main.cpp.i

CMakeFiles/question2.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/question2.dir/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haziq/Documents/algo2/Question2_Cmake/Main.cpp -o CMakeFiles/question2.dir/Main.cpp.s

CMakeFiles/question2.dir/Planet.cpp.o: CMakeFiles/question2.dir/flags.make
CMakeFiles/question2.dir/Planet.cpp.o: Planet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haziq/Documents/algo2/Question2_Cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/question2.dir/Planet.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/question2.dir/Planet.cpp.o -c /home/haziq/Documents/algo2/Question2_Cmake/Planet.cpp

CMakeFiles/question2.dir/Planet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/question2.dir/Planet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haziq/Documents/algo2/Question2_Cmake/Planet.cpp > CMakeFiles/question2.dir/Planet.cpp.i

CMakeFiles/question2.dir/Planet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/question2.dir/Planet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haziq/Documents/algo2/Question2_Cmake/Planet.cpp -o CMakeFiles/question2.dir/Planet.cpp.s

CMakeFiles/question2.dir/Graph.cpp.o: CMakeFiles/question2.dir/flags.make
CMakeFiles/question2.dir/Graph.cpp.o: Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haziq/Documents/algo2/Question2_Cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/question2.dir/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/question2.dir/Graph.cpp.o -c /home/haziq/Documents/algo2/Question2_Cmake/Graph.cpp

CMakeFiles/question2.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/question2.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haziq/Documents/algo2/Question2_Cmake/Graph.cpp > CMakeFiles/question2.dir/Graph.cpp.i

CMakeFiles/question2.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/question2.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haziq/Documents/algo2/Question2_Cmake/Graph.cpp -o CMakeFiles/question2.dir/Graph.cpp.s

# Object files for target question2
question2_OBJECTS = \
"CMakeFiles/question2.dir/Main.cpp.o" \
"CMakeFiles/question2.dir/Planet.cpp.o" \
"CMakeFiles/question2.dir/Graph.cpp.o"

# External object files for target question2
question2_EXTERNAL_OBJECTS =

question2: CMakeFiles/question2.dir/Main.cpp.o
question2: CMakeFiles/question2.dir/Planet.cpp.o
question2: CMakeFiles/question2.dir/Graph.cpp.o
question2: CMakeFiles/question2.dir/build.make
question2: CMakeFiles/question2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haziq/Documents/algo2/Question2_Cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable question2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/question2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/question2.dir/build: question2

.PHONY : CMakeFiles/question2.dir/build

CMakeFiles/question2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/question2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/question2.dir/clean

CMakeFiles/question2.dir/depend:
	cd /home/haziq/Documents/algo2/Question2_Cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haziq/Documents/algo2/Question2_Cmake /home/haziq/Documents/algo2/Question2_Cmake /home/haziq/Documents/algo2/Question2_Cmake /home/haziq/Documents/algo2/Question2_Cmake /home/haziq/Documents/algo2/Question2_Cmake/CMakeFiles/question2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/question2.dir/depend
