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
CMAKE_SOURCE_DIR = /home/nik/Sources/TLGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nik/Sources/TLGame/build

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/src/Game/Camera.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/Game/Camera.cpp.o: ../src/Game/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nik/Sources/TLGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run.dir/src/Game/Camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/Game/Camera.cpp.o -c /home/nik/Sources/TLGame/src/Game/Camera.cpp

CMakeFiles/run.dir/src/Game/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/Game/Camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nik/Sources/TLGame/src/Game/Camera.cpp > CMakeFiles/run.dir/src/Game/Camera.cpp.i

CMakeFiles/run.dir/src/Game/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/Game/Camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nik/Sources/TLGame/src/Game/Camera.cpp -o CMakeFiles/run.dir/src/Game/Camera.cpp.s

CMakeFiles/run.dir/src/Game/Camera.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/Game/Camera.cpp.o.requires

CMakeFiles/run.dir/src/Game/Camera.cpp.o.provides: CMakeFiles/run.dir/src/Game/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/Game/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/Game/Camera.cpp.o.provides

CMakeFiles/run.dir/src/Game/Camera.cpp.o.provides.build: CMakeFiles/run.dir/src/Game/Camera.cpp.o


CMakeFiles/run.dir/src/Game/Character.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/Game/Character.cpp.o: ../src/Game/Character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nik/Sources/TLGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run.dir/src/Game/Character.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/Game/Character.cpp.o -c /home/nik/Sources/TLGame/src/Game/Character.cpp

CMakeFiles/run.dir/src/Game/Character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/Game/Character.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nik/Sources/TLGame/src/Game/Character.cpp > CMakeFiles/run.dir/src/Game/Character.cpp.i

CMakeFiles/run.dir/src/Game/Character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/Game/Character.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nik/Sources/TLGame/src/Game/Character.cpp -o CMakeFiles/run.dir/src/Game/Character.cpp.s

CMakeFiles/run.dir/src/Game/Character.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/Game/Character.cpp.o.requires

CMakeFiles/run.dir/src/Game/Character.cpp.o.provides: CMakeFiles/run.dir/src/Game/Character.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/Game/Character.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/Game/Character.cpp.o.provides

CMakeFiles/run.dir/src/Game/Character.cpp.o.provides.build: CMakeFiles/run.dir/src/Game/Character.cpp.o


CMakeFiles/run.dir/src/Game/Level.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/Game/Level.cpp.o: ../src/Game/Level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nik/Sources/TLGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/run.dir/src/Game/Level.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/Game/Level.cpp.o -c /home/nik/Sources/TLGame/src/Game/Level.cpp

CMakeFiles/run.dir/src/Game/Level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/Game/Level.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nik/Sources/TLGame/src/Game/Level.cpp > CMakeFiles/run.dir/src/Game/Level.cpp.i

CMakeFiles/run.dir/src/Game/Level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/Game/Level.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nik/Sources/TLGame/src/Game/Level.cpp -o CMakeFiles/run.dir/src/Game/Level.cpp.s

CMakeFiles/run.dir/src/Game/Level.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/Game/Level.cpp.o.requires

CMakeFiles/run.dir/src/Game/Level.cpp.o.provides: CMakeFiles/run.dir/src/Game/Level.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/Game/Level.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/Game/Level.cpp.o.provides

CMakeFiles/run.dir/src/Game/Level.cpp.o.provides.build: CMakeFiles/run.dir/src/Game/Level.cpp.o


CMakeFiles/run.dir/src/Game/MainHero.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/Game/MainHero.cpp.o: ../src/Game/MainHero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nik/Sources/TLGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/run.dir/src/Game/MainHero.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/Game/MainHero.cpp.o -c /home/nik/Sources/TLGame/src/Game/MainHero.cpp

CMakeFiles/run.dir/src/Game/MainHero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/Game/MainHero.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nik/Sources/TLGame/src/Game/MainHero.cpp > CMakeFiles/run.dir/src/Game/MainHero.cpp.i

CMakeFiles/run.dir/src/Game/MainHero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/Game/MainHero.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nik/Sources/TLGame/src/Game/MainHero.cpp -o CMakeFiles/run.dir/src/Game/MainHero.cpp.s

CMakeFiles/run.dir/src/Game/MainHero.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/Game/MainHero.cpp.o.requires

CMakeFiles/run.dir/src/Game/MainHero.cpp.o.provides: CMakeFiles/run.dir/src/Game/MainHero.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/Game/MainHero.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/Game/MainHero.cpp.o.provides

CMakeFiles/run.dir/src/Game/MainHero.cpp.o.provides.build: CMakeFiles/run.dir/src/Game/MainHero.cpp.o


CMakeFiles/run.dir/src/Game/main.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/Game/main.cpp.o: ../src/Game/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nik/Sources/TLGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/run.dir/src/Game/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/Game/main.cpp.o -c /home/nik/Sources/TLGame/src/Game/main.cpp

CMakeFiles/run.dir/src/Game/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/Game/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nik/Sources/TLGame/src/Game/main.cpp > CMakeFiles/run.dir/src/Game/main.cpp.i

CMakeFiles/run.dir/src/Game/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/Game/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nik/Sources/TLGame/src/Game/main.cpp -o CMakeFiles/run.dir/src/Game/main.cpp.s

CMakeFiles/run.dir/src/Game/main.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/Game/main.cpp.o.requires

CMakeFiles/run.dir/src/Game/main.cpp.o.provides: CMakeFiles/run.dir/src/Game/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/Game/main.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/Game/main.cpp.o.provides

CMakeFiles/run.dir/src/Game/main.cpp.o.provides.build: CMakeFiles/run.dir/src/Game/main.cpp.o


# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/src/Game/Camera.cpp.o" \
"CMakeFiles/run.dir/src/Game/Character.cpp.o" \
"CMakeFiles/run.dir/src/Game/Level.cpp.o" \
"CMakeFiles/run.dir/src/Game/MainHero.cpp.o" \
"CMakeFiles/run.dir/src/Game/main.cpp.o"

# External object files for target run
run_EXTERNAL_OBJECTS =

run: CMakeFiles/run.dir/src/Game/Camera.cpp.o
run: CMakeFiles/run.dir/src/Game/Character.cpp.o
run: CMakeFiles/run.dir/src/Game/Level.cpp.o
run: CMakeFiles/run.dir/src/Game/MainHero.cpp.o
run: CMakeFiles/run.dir/src/Game/main.cpp.o
run: CMakeFiles/run.dir/build.make
run: CMakeFiles/run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nik/Sources/TLGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run

.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/Game/Camera.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/Game/Character.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/Game/Level.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/Game/MainHero.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/Game/main.cpp.o.requires

.PHONY : CMakeFiles/run.dir/requires

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /home/nik/Sources/TLGame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nik/Sources/TLGame /home/nik/Sources/TLGame /home/nik/Sources/TLGame/build /home/nik/Sources/TLGame/build /home/nik/Sources/TLGame/build/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend
