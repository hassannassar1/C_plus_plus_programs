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
CMAKE_SOURCE_DIR = /home/hassan/Desktop/image_filters

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hassan/Desktop/image_filters

# Include any dependencies generated for this target.
include CMakeFiles/ImageFilters.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageFilters.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageFilters.dir/flags.make

CMakeFiles/ImageFilters.dir/ImageFilters.cpp.o: CMakeFiles/ImageFilters.dir/flags.make
CMakeFiles/ImageFilters.dir/ImageFilters.cpp.o: ImageFilters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hassan/Desktop/image_filters/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageFilters.dir/ImageFilters.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageFilters.dir/ImageFilters.cpp.o -c /home/hassan/Desktop/image_filters/ImageFilters.cpp

CMakeFiles/ImageFilters.dir/ImageFilters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageFilters.dir/ImageFilters.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hassan/Desktop/image_filters/ImageFilters.cpp > CMakeFiles/ImageFilters.dir/ImageFilters.cpp.i

CMakeFiles/ImageFilters.dir/ImageFilters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageFilters.dir/ImageFilters.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hassan/Desktop/image_filters/ImageFilters.cpp -o CMakeFiles/ImageFilters.dir/ImageFilters.cpp.s

# Object files for target ImageFilters
ImageFilters_OBJECTS = \
"CMakeFiles/ImageFilters.dir/ImageFilters.cpp.o"

# External object files for target ImageFilters
ImageFilters_EXTERNAL_OBJECTS =

ImageFilters: CMakeFiles/ImageFilters.dir/ImageFilters.cpp.o
ImageFilters: CMakeFiles/ImageFilters.dir/build.make
ImageFilters: /usr/local/lib/libopencv_gapi.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_highgui.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_ml.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_objdetect.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_photo.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_stitching.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_video.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_videoio.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_dnn.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_calib3d.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_features2d.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_flann.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_imgproc.so.4.6.0
ImageFilters: /usr/local/lib/libopencv_core.so.4.6.0
ImageFilters: CMakeFiles/ImageFilters.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hassan/Desktop/image_filters/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ImageFilters"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageFilters.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageFilters.dir/build: ImageFilters

.PHONY : CMakeFiles/ImageFilters.dir/build

CMakeFiles/ImageFilters.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageFilters.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageFilters.dir/clean

CMakeFiles/ImageFilters.dir/depend:
	cd /home/hassan/Desktop/image_filters && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hassan/Desktop/image_filters /home/hassan/Desktop/image_filters /home/hassan/Desktop/image_filters /home/hassan/Desktop/image_filters /home/hassan/Desktop/image_filters/CMakeFiles/ImageFilters.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageFilters.dir/depend
