# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\CLionProjects\omp01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\CLionProjects\omp01\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/repaso.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/repaso.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/repaso.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/repaso.dir/flags.make

CMakeFiles/repaso.dir/repaso.cpp.obj: CMakeFiles/repaso.dir/flags.make
CMakeFiles/repaso.dir/repaso.cpp.obj: C:/Users/User/CLionProjects/omp01/repaso.cpp
CMakeFiles/repaso.dir/repaso.cpp.obj: CMakeFiles/repaso.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\CLionProjects\omp01\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/repaso.dir/repaso.cpp.obj"
	C:\clang64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/repaso.dir/repaso.cpp.obj -MF CMakeFiles\repaso.dir\repaso.cpp.obj.d -o CMakeFiles\repaso.dir\repaso.cpp.obj -c C:\Users\User\CLionProjects\omp01\repaso.cpp

CMakeFiles/repaso.dir/repaso.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/repaso.dir/repaso.cpp.i"
	C:\clang64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\CLionProjects\omp01\repaso.cpp > CMakeFiles\repaso.dir\repaso.cpp.i

CMakeFiles/repaso.dir/repaso.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/repaso.dir/repaso.cpp.s"
	C:\clang64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\CLionProjects\omp01\repaso.cpp -o CMakeFiles\repaso.dir\repaso.cpp.s

# Object files for target repaso
repaso_OBJECTS = \
"CMakeFiles/repaso.dir/repaso.cpp.obj"

# External object files for target repaso
repaso_EXTERNAL_OBJECTS =

repaso.exe: CMakeFiles/repaso.dir/repaso.cpp.obj
repaso.exe: CMakeFiles/repaso.dir/build.make
repaso.exe: CMakeFiles/repaso.dir/linklibs.rsp
repaso.exe: CMakeFiles/repaso.dir/objects1.rsp
repaso.exe: CMakeFiles/repaso.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\CLionProjects\omp01\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable repaso.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\repaso.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/repaso.dir/build: repaso.exe
.PHONY : CMakeFiles/repaso.dir/build

CMakeFiles/repaso.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\repaso.dir\cmake_clean.cmake
.PHONY : CMakeFiles/repaso.dir/clean

CMakeFiles/repaso.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\CLionProjects\omp01 C:\Users\User\CLionProjects\omp01 C:\Users\User\CLionProjects\omp01\cmake-build-release C:\Users\User\CLionProjects\omp01\cmake-build-release C:\Users\User\CLionProjects\omp01\cmake-build-release\CMakeFiles\repaso.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/repaso.dir/depend
