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
CMAKE_SOURCE_DIR = /home/pyp/face_app/face_platform

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pyp/face_app/face_platform/cmake-build-debug

# Include any dependencies generated for this target.
include models/recognization/CMakeFiles/recognization.dir/depend.make

# Include the progress variables for this target.
include models/recognization/CMakeFiles/recognization.dir/progress.make

# Include the compile flags for this target's objects.
include models/recognization/CMakeFiles/recognization.dir/flags.make

models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o: models/recognization/CMakeFiles/recognization.dir/flags.make
models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o: ../models/recognization/recognization.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pyp/face_app/face_platform/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o"
	cd /home/pyp/face_app/face_platform/cmake-build-debug/models/recognization && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/recognization.dir/recognization.cpp.o -c /home/pyp/face_app/face_platform/models/recognization/recognization.cpp

models/recognization/CMakeFiles/recognization.dir/recognization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recognization.dir/recognization.cpp.i"
	cd /home/pyp/face_app/face_platform/cmake-build-debug/models/recognization && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pyp/face_app/face_platform/models/recognization/recognization.cpp > CMakeFiles/recognization.dir/recognization.cpp.i

models/recognization/CMakeFiles/recognization.dir/recognization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recognization.dir/recognization.cpp.s"
	cd /home/pyp/face_app/face_platform/cmake-build-debug/models/recognization && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pyp/face_app/face_platform/models/recognization/recognization.cpp -o CMakeFiles/recognization.dir/recognization.cpp.s

models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o.requires:

.PHONY : models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o.requires

models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o.provides: models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o.requires
	$(MAKE) -f models/recognization/CMakeFiles/recognization.dir/build.make models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o.provides.build
.PHONY : models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o.provides

models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o.provides.build: models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o


# Object files for target recognization
recognization_OBJECTS = \
"CMakeFiles/recognization.dir/recognization.cpp.o"

# External object files for target recognization
recognization_EXTERNAL_OBJECTS =

models/recognization/recognization: models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o
models/recognization/recognization: models/recognization/CMakeFiles/recognization.dir/build.make
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_img_hash.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/lib/libdlib.a
models/recognization/recognization: /usr/local/lib/libopencv_world.so.4.0.0
models/recognization/recognization: /usr/local/cuda/lib64/libcudart_static.a
models/recognization/recognization: /usr/lib/x86_64-linux-gnu/librt.so
models/recognization/recognization: /usr/lib/x86_64-linux-gnu/librt.so
models/recognization/recognization: /usr/lib/x86_64-linux-gnu/libnsl.so
models/recognization/recognization: /usr/lib/x86_64-linux-gnu/libSM.so
models/recognization/recognization: /usr/lib/x86_64-linux-gnu/libICE.so
models/recognization/recognization: /usr/lib/x86_64-linux-gnu/libX11.so
models/recognization/recognization: /usr/lib/x86_64-linux-gnu/libXext.so
models/recognization/recognization: /home/pyp/anaconda3/lib/libpng.so
models/recognization/recognization: /home/pyp/anaconda3/lib/libz.so
models/recognization/recognization: /home/pyp/anaconda3/lib/libmkl_rt.so
models/recognization/recognization: /usr/local/cuda/lib64/libcublas.so
models/recognization/recognization: /usr/lib/libcudnn.so
models/recognization/recognization: /usr/local/cuda/lib64/libcurand.so
models/recognization/recognization: /usr/local/cuda/lib64/libcusolver.so
models/recognization/recognization: /home/pyp/anaconda3/lib/libiomp5.so
models/recognization/recognization: /home/pyp/anaconda3/lib/libsqlite3.so
models/recognization/recognization: models/recognization/CMakeFiles/recognization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pyp/face_app/face_platform/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable recognization"
	cd /home/pyp/face_app/face_platform/cmake-build-debug/models/recognization && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recognization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
models/recognization/CMakeFiles/recognization.dir/build: models/recognization/recognization

.PHONY : models/recognization/CMakeFiles/recognization.dir/build

models/recognization/CMakeFiles/recognization.dir/requires: models/recognization/CMakeFiles/recognization.dir/recognization.cpp.o.requires

.PHONY : models/recognization/CMakeFiles/recognization.dir/requires

models/recognization/CMakeFiles/recognization.dir/clean:
	cd /home/pyp/face_app/face_platform/cmake-build-debug/models/recognization && $(CMAKE_COMMAND) -P CMakeFiles/recognization.dir/cmake_clean.cmake
.PHONY : models/recognization/CMakeFiles/recognization.dir/clean

models/recognization/CMakeFiles/recognization.dir/depend:
	cd /home/pyp/face_app/face_platform/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pyp/face_app/face_platform /home/pyp/face_app/face_platform/models/recognization /home/pyp/face_app/face_platform/cmake-build-debug /home/pyp/face_app/face_platform/cmake-build-debug/models/recognization /home/pyp/face_app/face_platform/cmake-build-debug/models/recognization/CMakeFiles/recognization.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : models/recognization/CMakeFiles/recognization.dir/depend

