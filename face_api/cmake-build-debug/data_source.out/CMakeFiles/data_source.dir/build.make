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
CMAKE_COMMAND = /home/pyp/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/pyp/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pyp/face_app/face_platform/face_api

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pyp/face_app/face_platform/face_api/cmake-build-debug

# Include any dependencies generated for this target.
include data_source.out/CMakeFiles/data_source.dir/depend.make

# Include the progress variables for this target.
include data_source.out/CMakeFiles/data_source.dir/progress.make

# Include the compile flags for this target's objects.
include data_source.out/CMakeFiles/data_source.dir/flags.make

data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o: data_source.out/CMakeFiles/data_source.dir/flags.make
data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o: /home/pyp/face_app/face_platform/models/data_source/data_source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pyp/face_app/face_platform/face_api/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o"
	cd /home/pyp/face_app/face_platform/face_api/cmake-build-debug/data_source.out && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/data_source.dir/data_source.cpp.o -c /home/pyp/face_app/face_platform/models/data_source/data_source.cpp

data_source.out/CMakeFiles/data_source.dir/data_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_source.dir/data_source.cpp.i"
	cd /home/pyp/face_app/face_platform/face_api/cmake-build-debug/data_source.out && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pyp/face_app/face_platform/models/data_source/data_source.cpp > CMakeFiles/data_source.dir/data_source.cpp.i

data_source.out/CMakeFiles/data_source.dir/data_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_source.dir/data_source.cpp.s"
	cd /home/pyp/face_app/face_platform/face_api/cmake-build-debug/data_source.out && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pyp/face_app/face_platform/models/data_source/data_source.cpp -o CMakeFiles/data_source.dir/data_source.cpp.s

data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o.requires:

.PHONY : data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o.requires

data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o.provides: data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o.requires
	$(MAKE) -f data_source.out/CMakeFiles/data_source.dir/build.make data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o.provides.build
.PHONY : data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o.provides

data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o.provides.build: data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o


# Object files for target data_source
data_source_OBJECTS = \
"CMakeFiles/data_source.dir/data_source.cpp.o"

# External object files for target data_source
data_source_EXTERNAL_OBJECTS =

data_source.out/libdata_source.a: data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o
data_source.out/libdata_source.a: data_source.out/CMakeFiles/data_source.dir/build.make
data_source.out/libdata_source.a: data_source.out/CMakeFiles/data_source.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pyp/face_app/face_platform/face_api/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdata_source.a"
	cd /home/pyp/face_app/face_platform/face_api/cmake-build-debug/data_source.out && $(CMAKE_COMMAND) -P CMakeFiles/data_source.dir/cmake_clean_target.cmake
	cd /home/pyp/face_app/face_platform/face_api/cmake-build-debug/data_source.out && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_source.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
data_source.out/CMakeFiles/data_source.dir/build: data_source.out/libdata_source.a

.PHONY : data_source.out/CMakeFiles/data_source.dir/build

data_source.out/CMakeFiles/data_source.dir/requires: data_source.out/CMakeFiles/data_source.dir/data_source.cpp.o.requires

.PHONY : data_source.out/CMakeFiles/data_source.dir/requires

data_source.out/CMakeFiles/data_source.dir/clean:
	cd /home/pyp/face_app/face_platform/face_api/cmake-build-debug/data_source.out && $(CMAKE_COMMAND) -P CMakeFiles/data_source.dir/cmake_clean.cmake
.PHONY : data_source.out/CMakeFiles/data_source.dir/clean

data_source.out/CMakeFiles/data_source.dir/depend:
	cd /home/pyp/face_app/face_platform/face_api/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pyp/face_app/face_platform/face_api /home/pyp/face_app/face_platform/models/data_source /home/pyp/face_app/face_platform/face_api/cmake-build-debug /home/pyp/face_app/face_platform/face_api/cmake-build-debug/data_source.out /home/pyp/face_app/face_platform/face_api/cmake-build-debug/data_source.out/CMakeFiles/data_source.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : data_source.out/CMakeFiles/data_source.dir/depend

