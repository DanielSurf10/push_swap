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
CMAKE_SOURCE_DIR = "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/visualizer.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/visualizer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/visualizer.dir/flags.make

src/CMakeFiles/visualizer.dir/main.cpp.o: src/CMakeFiles/visualizer.dir/flags.make
src/CMakeFiles/visualizer.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/visualizer.dir/main.cpp.o"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/visualizer.dir/main.cpp.o -c "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/src/main.cpp"

src/CMakeFiles/visualizer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/visualizer.dir/main.cpp.i"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/src/main.cpp" > CMakeFiles/visualizer.dir/main.cpp.i

src/CMakeFiles/visualizer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/visualizer.dir/main.cpp.s"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/src/main.cpp" -o CMakeFiles/visualizer.dir/main.cpp.s

# Object files for target visualizer
visualizer_OBJECTS = \
"CMakeFiles/visualizer.dir/main.cpp.o"

# External object files for target visualizer
visualizer_EXTERNAL_OBJECTS =

bin/visualizer: src/CMakeFiles/visualizer.dir/main.cpp.o
bin/visualizer: src/CMakeFiles/visualizer.dir/build.make
bin/visualizer: src/libVisualizerLib.a
bin/visualizer: _deps/imgui-sfml-build/libImGui-SFML.a
bin/visualizer: _deps/sfml-build/lib/libsfml-graphics.so.2.5.1
bin/visualizer: _deps/sfml-build/lib/libsfml-window.so.2.5.1
bin/visualizer: _deps/sfml-build/lib/libsfml-system.so.2.5.1
bin/visualizer: /usr/lib/x86_64-linux-gnu/libGL.so
bin/visualizer: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/visualizer: src/CMakeFiles/visualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/visualizer"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/visualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/visualizer.dir/build: bin/visualizer

.PHONY : src/CMakeFiles/visualizer.dir/build

src/CMakeFiles/visualizer.dir/clean:
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/visualizer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/visualizer.dir/clean

src/CMakeFiles/visualizer.dir/depend:
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/src" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/src" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/src/CMakeFiles/visualizer.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/visualizer.dir/depend

