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
include _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/depend.make

# Include the progress variables for this target.
include _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/flags.make

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.o: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/flags.make
_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.o: _deps/imgui-sfml-src/imgui-SFML.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.o"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.o -c "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-src/imgui-SFML.cpp"

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.i"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-src/imgui-SFML.cpp" > CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.i

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.s"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-src/imgui-SFML.cpp" -o CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.s

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.o: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/flags.make
_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.o: _deps/imgui-src/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.o"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.o -c "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui.cpp"

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.i"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui.cpp" > CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.i

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.s"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui.cpp" -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.s

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.o: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/flags.make
_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.o: _deps/imgui-src/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.o"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.o -c "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_draw.cpp"

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.i"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_draw.cpp" > CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.i

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.s"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_draw.cpp" -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.s

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.o: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/flags.make
_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.o: _deps/imgui-src/imgui_tables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.o"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.o -c "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_tables.cpp"

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.i"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_tables.cpp" > CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.i

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.s"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_tables.cpp" -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.s

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.o: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/flags.make
_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.o: _deps/imgui-src/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.o"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.o -c "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_widgets.cpp"

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.i"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_widgets.cpp" > CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.i

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.s"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/imgui_widgets.cpp" -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.s

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.o: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/flags.make
_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.o: _deps/imgui-src/misc/cpp/imgui_stdlib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.o"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.o -c "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/misc/cpp/imgui_stdlib.cpp"

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.i"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/misc/cpp/imgui_stdlib.cpp" > CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.i

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.s"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-src/misc/cpp/imgui_stdlib.cpp" -o CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.s

# Object files for target ImGui-SFML
ImGui__SFML_OBJECTS = \
"CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.o" \
"CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.o" \
"CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.o" \
"CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.o" \
"CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.o" \
"CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.o"

# External object files for target ImGui-SFML
ImGui__SFML_EXTERNAL_OBJECTS =

_deps/imgui-sfml-build/libImGui-SFML.a: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/imgui-SFML.cpp.o
_deps/imgui-sfml-build/libImGui-SFML.a: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui.cpp.o
_deps/imgui-sfml-build/libImGui-SFML.a: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_draw.cpp.o
_deps/imgui-sfml-build/libImGui-SFML.a: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_tables.cpp.o
_deps/imgui-sfml-build/libImGui-SFML.a: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/imgui_widgets.cpp.o
_deps/imgui-sfml-build/libImGui-SFML.a: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/__/imgui-src/misc/cpp/imgui_stdlib.cpp.o
_deps/imgui-sfml-build/libImGui-SFML.a: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/build.make
_deps/imgui-sfml-build/libImGui-SFML.a: _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libImGui-SFML.a"
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && $(CMAKE_COMMAND) -P CMakeFiles/ImGui-SFML.dir/cmake_clean_target.cmake
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImGui-SFML.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/build: _deps/imgui-sfml-build/libImGui-SFML.a

.PHONY : _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/build

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/clean:
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" && $(CMAKE_COMMAND) -P CMakeFiles/ImGui-SFML.dir/cmake_clean.cmake
.PHONY : _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/clean

_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/depend:
	cd "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-src" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build" "/nfs/homes/danbarbo/projetos/08 - push_swap/push_swap_visualizer/build/_deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : _deps/imgui-sfml-build/CMakeFiles/ImGui-SFML.dir/depend

