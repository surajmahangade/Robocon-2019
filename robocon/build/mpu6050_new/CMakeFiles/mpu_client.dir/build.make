# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/robocon/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/robocon/build

# Include any dependencies generated for this target.
include mpu6050_new/CMakeFiles/mpu_client.dir/depend.make

# Include the progress variables for this target.
include mpu6050_new/CMakeFiles/mpu_client.dir/progress.make

# Include the compile flags for this target's objects.
include mpu6050_new/CMakeFiles/mpu_client.dir/flags.make

mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o: mpu6050_new/CMakeFiles/mpu_client.dir/flags.make
mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o: /home/pi/robocon/src/mpu6050_new/src/mpu_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/robocon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o"
	cd /home/pi/robocon/build/mpu6050_new && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o -c /home/pi/robocon/src/mpu6050_new/src/mpu_client.cpp

mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mpu_client.dir/src/mpu_client.cpp.i"
	cd /home/pi/robocon/build/mpu6050_new && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/robocon/src/mpu6050_new/src/mpu_client.cpp > CMakeFiles/mpu_client.dir/src/mpu_client.cpp.i

mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mpu_client.dir/src/mpu_client.cpp.s"
	cd /home/pi/robocon/build/mpu6050_new && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/robocon/src/mpu6050_new/src/mpu_client.cpp -o CMakeFiles/mpu_client.dir/src/mpu_client.cpp.s

mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o.requires:

.PHONY : mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o.requires

mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o.provides: mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o.requires
	$(MAKE) -f mpu6050_new/CMakeFiles/mpu_client.dir/build.make mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o.provides.build
.PHONY : mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o.provides

mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o.provides.build: mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o


# Object files for target mpu_client
mpu_client_OBJECTS = \
"CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o"

# External object files for target mpu_client
mpu_client_EXTERNAL_OBJECTS =

/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: mpu6050_new/CMakeFiles/mpu_client.dir/build.make
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /opt/ros/kinetic/lib/libroscpp.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /opt/ros/kinetic/lib/librosconsole.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/liblog4cxx.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /opt/ros/kinetic/lib/librostime.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /opt/ros/kinetic/lib/libcpp_common.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/pi/robocon/devel/lib/mpu6050_new/mpu_client: mpu6050_new/CMakeFiles/mpu_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/robocon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/pi/robocon/devel/lib/mpu6050_new/mpu_client"
	cd /home/pi/robocon/build/mpu6050_new && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mpu_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mpu6050_new/CMakeFiles/mpu_client.dir/build: /home/pi/robocon/devel/lib/mpu6050_new/mpu_client

.PHONY : mpu6050_new/CMakeFiles/mpu_client.dir/build

mpu6050_new/CMakeFiles/mpu_client.dir/requires: mpu6050_new/CMakeFiles/mpu_client.dir/src/mpu_client.cpp.o.requires

.PHONY : mpu6050_new/CMakeFiles/mpu_client.dir/requires

mpu6050_new/CMakeFiles/mpu_client.dir/clean:
	cd /home/pi/robocon/build/mpu6050_new && $(CMAKE_COMMAND) -P CMakeFiles/mpu_client.dir/cmake_clean.cmake
.PHONY : mpu6050_new/CMakeFiles/mpu_client.dir/clean

mpu6050_new/CMakeFiles/mpu_client.dir/depend:
	cd /home/pi/robocon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/robocon/src /home/pi/robocon/src/mpu6050_new /home/pi/robocon/build /home/pi/robocon/build/mpu6050_new /home/pi/robocon/build/mpu6050_new/CMakeFiles/mpu_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mpu6050_new/CMakeFiles/mpu_client.dir/depend

