# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = "C:\Users\Bansy\CLionProjects\DAA MID-SEM"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Bansy\CLionProjects\DAA MID-SEM\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DAA_MID_SEM.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/DAA_MID_SEM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DAA_MID_SEM.dir/flags.make

CMakeFiles/DAA_MID_SEM.dir/main.cpp.obj: CMakeFiles/DAA_MID_SEM.dir/flags.make
CMakeFiles/DAA_MID_SEM.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bansy\CLionProjects\DAA MID-SEM\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DAA_MID_SEM.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_MID_SEM.dir\main.cpp.obj -c "C:\Users\Bansy\CLionProjects\DAA MID-SEM\main.cpp"

CMakeFiles/DAA_MID_SEM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_MID_SEM.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Bansy\CLionProjects\DAA MID-SEM\main.cpp" > CMakeFiles\DAA_MID_SEM.dir\main.cpp.i

CMakeFiles/DAA_MID_SEM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_MID_SEM.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Bansy\CLionProjects\DAA MID-SEM\main.cpp" -o CMakeFiles\DAA_MID_SEM.dir\main.cpp.s

# Object files for target DAA_MID_SEM
DAA_MID_SEM_OBJECTS = \
"CMakeFiles/DAA_MID_SEM.dir/main.cpp.obj"

# External object files for target DAA_MID_SEM
DAA_MID_SEM_EXTERNAL_OBJECTS =

DAA_MID_SEM.exe: CMakeFiles/DAA_MID_SEM.dir/main.cpp.obj
DAA_MID_SEM.exe: CMakeFiles/DAA_MID_SEM.dir/build.make
DAA_MID_SEM.exe: CMakeFiles/DAA_MID_SEM.dir/linklibs.rsp
DAA_MID_SEM.exe: CMakeFiles/DAA_MID_SEM.dir/objects1.rsp
DAA_MID_SEM.exe: CMakeFiles/DAA_MID_SEM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Bansy\CLionProjects\DAA MID-SEM\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DAA_MID_SEM.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DAA_MID_SEM.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DAA_MID_SEM.dir/build: DAA_MID_SEM.exe
.PHONY : CMakeFiles/DAA_MID_SEM.dir/build

CMakeFiles/DAA_MID_SEM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DAA_MID_SEM.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DAA_MID_SEM.dir/clean

CMakeFiles/DAA_MID_SEM.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Bansy\CLionProjects\DAA MID-SEM" "C:\Users\Bansy\CLionProjects\DAA MID-SEM" "C:\Users\Bansy\CLionProjects\DAA MID-SEM\cmake-build-debug" "C:\Users\Bansy\CLionProjects\DAA MID-SEM\cmake-build-debug" "C:\Users\Bansy\CLionProjects\DAA MID-SEM\cmake-build-debug\CMakeFiles\DAA_MID_SEM.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DAA_MID_SEM.dir/depend

