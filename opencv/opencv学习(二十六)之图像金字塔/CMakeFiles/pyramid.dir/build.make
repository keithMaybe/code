# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔"

# Include any dependencies generated for this target.
include CMakeFiles/pyramid.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pyramid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pyramid.dir/flags.make

CMakeFiles/pyramid.dir/pyramid.cpp.o: CMakeFiles/pyramid.dir/flags.make
CMakeFiles/pyramid.dir/pyramid.cpp.o: pyramid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/keith/program/opencv/opencv学习(二十六)之图像金字塔/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pyramid.dir/pyramid.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pyramid.dir/pyramid.cpp.o -c "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔/pyramid.cpp"

CMakeFiles/pyramid.dir/pyramid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyramid.dir/pyramid.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔/pyramid.cpp" > CMakeFiles/pyramid.dir/pyramid.cpp.i

CMakeFiles/pyramid.dir/pyramid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyramid.dir/pyramid.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔/pyramid.cpp" -o CMakeFiles/pyramid.dir/pyramid.cpp.s

CMakeFiles/pyramid.dir/pyramid.cpp.o.requires:

.PHONY : CMakeFiles/pyramid.dir/pyramid.cpp.o.requires

CMakeFiles/pyramid.dir/pyramid.cpp.o.provides: CMakeFiles/pyramid.dir/pyramid.cpp.o.requires
	$(MAKE) -f CMakeFiles/pyramid.dir/build.make CMakeFiles/pyramid.dir/pyramid.cpp.o.provides.build
.PHONY : CMakeFiles/pyramid.dir/pyramid.cpp.o.provides

CMakeFiles/pyramid.dir/pyramid.cpp.o.provides.build: CMakeFiles/pyramid.dir/pyramid.cpp.o


# Object files for target pyramid
pyramid_OBJECTS = \
"CMakeFiles/pyramid.dir/pyramid.cpp.o"

# External object files for target pyramid
pyramid_EXTERNAL_OBJECTS =

pyramid: CMakeFiles/pyramid.dir/pyramid.cpp.o
pyramid: CMakeFiles/pyramid.dir/build.make
pyramid: /usr/local/lib/libopencv_shape.so.3.2.0
pyramid: /usr/local/lib/libopencv_stitching.so.3.2.0
pyramid: /usr/local/lib/libopencv_superres.so.3.2.0
pyramid: /usr/local/lib/libopencv_videostab.so.3.2.0
pyramid: /usr/local/lib/libopencv_objdetect.so.3.2.0
pyramid: /usr/local/lib/libopencv_calib3d.so.3.2.0
pyramid: /usr/local/lib/libopencv_features2d.so.3.2.0
pyramid: /usr/local/lib/libopencv_flann.so.3.2.0
pyramid: /usr/local/lib/libopencv_highgui.so.3.2.0
pyramid: /usr/local/lib/libopencv_ml.so.3.2.0
pyramid: /usr/local/lib/libopencv_photo.so.3.2.0
pyramid: /usr/local/lib/libopencv_video.so.3.2.0
pyramid: /usr/local/lib/libopencv_videoio.so.3.2.0
pyramid: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
pyramid: /usr/local/lib/libopencv_imgproc.so.3.2.0
pyramid: /usr/local/lib/libopencv_core.so.3.2.0
pyramid: CMakeFiles/pyramid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/keith/program/opencv/opencv学习(二十六)之图像金字塔/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pyramid"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pyramid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pyramid.dir/build: pyramid

.PHONY : CMakeFiles/pyramid.dir/build

CMakeFiles/pyramid.dir/requires: CMakeFiles/pyramid.dir/pyramid.cpp.o.requires

.PHONY : CMakeFiles/pyramid.dir/requires

CMakeFiles/pyramid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pyramid.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pyramid.dir/clean

CMakeFiles/pyramid.dir/depend:
	cd "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔" "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔" "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔" "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔" "/home/keith/program/opencv/opencv学习(二十六)之图像金字塔/CMakeFiles/pyramid.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pyramid.dir/depend

