# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DSAA_LAB_18_05_2021.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DSAA_LAB_18_05_2021.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSAA_LAB_18_05_2021.dir/flags.make

CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.obj: CMakeFiles/DSAA_LAB_18_05_2021.dir/flags.make
CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DSAA_LAB_18_05_2021.dir\main.c.obj -c C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\main.c

CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\main.c > CMakeFiles\DSAA_LAB_18_05_2021.dir\main.c.i

CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\main.c -o CMakeFiles\DSAA_LAB_18_05_2021.dir\main.c.s

# Object files for target DSAA_LAB_18_05_2021
DSAA_LAB_18_05_2021_OBJECTS = \
"CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.obj"

# External object files for target DSAA_LAB_18_05_2021
DSAA_LAB_18_05_2021_EXTERNAL_OBJECTS =

DSAA_LAB_18_05_2021.exe: CMakeFiles/DSAA_LAB_18_05_2021.dir/main.c.obj
DSAA_LAB_18_05_2021.exe: CMakeFiles/DSAA_LAB_18_05_2021.dir/build.make
DSAA_LAB_18_05_2021.exe: CMakeFiles/DSAA_LAB_18_05_2021.dir/linklibs.rsp
DSAA_LAB_18_05_2021.exe: CMakeFiles/DSAA_LAB_18_05_2021.dir/objects1.rsp
DSAA_LAB_18_05_2021.exe: CMakeFiles/DSAA_LAB_18_05_2021.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DSAA_LAB_18_05_2021.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DSAA_LAB_18_05_2021.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSAA_LAB_18_05_2021.dir/build: DSAA_LAB_18_05_2021.exe

.PHONY : CMakeFiles/DSAA_LAB_18_05_2021.dir/build

CMakeFiles/DSAA_LAB_18_05_2021.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DSAA_LAB_18_05_2021.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DSAA_LAB_18_05_2021.dir/clean

CMakeFiles/DSAA_LAB_18_05_2021.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021 C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021 C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\cmake-build-debug C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\cmake-build-debug C:\Users\Bansy\CLionProjects\DSAA_LAB_18_05_2021\cmake-build-debug\CMakeFiles\DSAA_LAB_18_05_2021.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DSAA_LAB_18_05_2021.dir/depend

