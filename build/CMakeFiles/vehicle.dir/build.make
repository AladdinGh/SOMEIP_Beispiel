# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/build

# Include any dependencies generated for this target.
include CMakeFiles/vehicle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vehicle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vehicle.dir/flags.make

CMakeFiles/vehicle.dir/vehicle.cpp.o: CMakeFiles/vehicle.dir/flags.make
CMakeFiles/vehicle.dir/vehicle.cpp.o: ../vehicle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vehicle.dir/vehicle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vehicle.dir/vehicle.cpp.o -c /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/vehicle.cpp

CMakeFiles/vehicle.dir/vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vehicle.dir/vehicle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/vehicle.cpp > CMakeFiles/vehicle.dir/vehicle.cpp.i

CMakeFiles/vehicle.dir/vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vehicle.dir/vehicle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/vehicle.cpp -o CMakeFiles/vehicle.dir/vehicle.cpp.s

CMakeFiles/vehicle.dir/vehicle.cpp.o.requires:

.PHONY : CMakeFiles/vehicle.dir/vehicle.cpp.o.requires

CMakeFiles/vehicle.dir/vehicle.cpp.o.provides: CMakeFiles/vehicle.dir/vehicle.cpp.o.requires
	$(MAKE) -f CMakeFiles/vehicle.dir/build.make CMakeFiles/vehicle.dir/vehicle.cpp.o.provides.build
.PHONY : CMakeFiles/vehicle.dir/vehicle.cpp.o.provides

CMakeFiles/vehicle.dir/vehicle.cpp.o.provides.build: CMakeFiles/vehicle.dir/vehicle.cpp.o


# Object files for target vehicle
vehicle_OBJECTS = \
"CMakeFiles/vehicle.dir/vehicle.cpp.o"

# External object files for target vehicle
vehicle_EXTERNAL_OBJECTS =

vehicle: CMakeFiles/vehicle.dir/vehicle.cpp.o
vehicle: CMakeFiles/vehicle.dir/build.make
vehicle: /usr/local/lib/libvsomeip.so.2.8.0
vehicle: /usr/lib/x86_64-linux-gnu/libboost_system.so
vehicle: /usr/lib/x86_64-linux-gnu/libboost_thread.so
vehicle: /usr/lib/x86_64-linux-gnu/libboost_log.so
vehicle: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
vehicle: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
vehicle: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
vehicle: /usr/lib/x86_64-linux-gnu/libboost_log_setup.so
vehicle: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
vehicle: /usr/lib/x86_64-linux-gnu/libboost_regex.so
vehicle: /usr/lib/x86_64-linux-gnu/libpthread.so
vehicle: CMakeFiles/vehicle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vehicle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vehicle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vehicle.dir/build: vehicle

.PHONY : CMakeFiles/vehicle.dir/build

CMakeFiles/vehicle.dir/requires: CMakeFiles/vehicle.dir/vehicle.cpp.o.requires

.PHONY : CMakeFiles/vehicle.dir/requires

CMakeFiles/vehicle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vehicle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vehicle.dir/clean

CMakeFiles/vehicle.dir/depend:
	cd /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/build /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/build /home/aladdin/Desktop/Projects/SOME_IP_Example/Training_examples-e/Example_subscribe_notify/build/CMakeFiles/vehicle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vehicle.dir/depend

