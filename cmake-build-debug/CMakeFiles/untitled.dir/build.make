# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/Luiz Tavares/Documents/algtrab"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untitled.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/main.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/main.c.o: ../main.c
CMakeFiles/untitled.dir/main.c.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled.dir/main.c.o -MF CMakeFiles/untitled.dir/main.c.o.d -o CMakeFiles/untitled.dir/main.c.o -c "/mnt/c/Users/Luiz Tavares/Documents/algtrab/main.c"

CMakeFiles/untitled.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Luiz Tavares/Documents/algtrab/main.c" > CMakeFiles/untitled.dir/main.c.i

CMakeFiles/untitled.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Luiz Tavares/Documents/algtrab/main.c" -o CMakeFiles/untitled.dir/main.c.s

CMakeFiles/untitled.dir/utils.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/utils.c.o: ../utils.c
CMakeFiles/untitled.dir/utils.c.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled.dir/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled.dir/utils.c.o -MF CMakeFiles/untitled.dir/utils.c.o.d -o CMakeFiles/untitled.dir/utils.c.o -c "/mnt/c/Users/Luiz Tavares/Documents/algtrab/utils.c"

CMakeFiles/untitled.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Luiz Tavares/Documents/algtrab/utils.c" > CMakeFiles/untitled.dir/utils.c.i

CMakeFiles/untitled.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Luiz Tavares/Documents/algtrab/utils.c" -o CMakeFiles/untitled.dir/utils.c.s

CMakeFiles/untitled.dir/readProcess.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/readProcess.c.o: ../readProcess.c
CMakeFiles/untitled.dir/readProcess.c.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled.dir/readProcess.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled.dir/readProcess.c.o -MF CMakeFiles/untitled.dir/readProcess.c.o.d -o CMakeFiles/untitled.dir/readProcess.c.o -c "/mnt/c/Users/Luiz Tavares/Documents/algtrab/readProcess.c"

CMakeFiles/untitled.dir/readProcess.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/readProcess.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Luiz Tavares/Documents/algtrab/readProcess.c" > CMakeFiles/untitled.dir/readProcess.c.i

CMakeFiles/untitled.dir/readProcess.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/readProcess.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Luiz Tavares/Documents/algtrab/readProcess.c" -o CMakeFiles/untitled.dir/readProcess.c.s

CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o: ../mangaSecundaryIndexManege.c
CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o -MF CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o.d -o CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o -c "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaSecundaryIndexManege.c"

CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaSecundaryIndexManege.c" > CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.i

CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaSecundaryIndexManege.c" -o CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.s

CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o: ../mangaPrimaryIndexManage.c
CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o -MF CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o.d -o CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o -c "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaPrimaryIndexManage.c"

CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaPrimaryIndexManage.c" > CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.i

CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaPrimaryIndexManage.c" -o CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.s

CMakeFiles/untitled.dir/mangaDataFileManage.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/mangaDataFileManage.c.o: ../mangaDataFileManage.c
CMakeFiles/untitled.dir/mangaDataFileManage.c.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/untitled.dir/mangaDataFileManage.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled.dir/mangaDataFileManage.c.o -MF CMakeFiles/untitled.dir/mangaDataFileManage.c.o.d -o CMakeFiles/untitled.dir/mangaDataFileManage.c.o -c "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaDataFileManage.c"

CMakeFiles/untitled.dir/mangaDataFileManage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/mangaDataFileManage.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaDataFileManage.c" > CMakeFiles/untitled.dir/mangaDataFileManage.c.i

CMakeFiles/untitled.dir/mangaDataFileManage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/mangaDataFileManage.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Luiz Tavares/Documents/algtrab/mangaDataFileManage.c" -o CMakeFiles/untitled.dir/mangaDataFileManage.c.s

CMakeFiles/untitled.dir/deleteProcess.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/deleteProcess.c.o: ../deleteProcess.c
CMakeFiles/untitled.dir/deleteProcess.c.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/untitled.dir/deleteProcess.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled.dir/deleteProcess.c.o -MF CMakeFiles/untitled.dir/deleteProcess.c.o.d -o CMakeFiles/untitled.dir/deleteProcess.c.o -c "/mnt/c/Users/Luiz Tavares/Documents/algtrab/deleteProcess.c"

CMakeFiles/untitled.dir/deleteProcess.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/deleteProcess.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Luiz Tavares/Documents/algtrab/deleteProcess.c" > CMakeFiles/untitled.dir/deleteProcess.c.i

CMakeFiles/untitled.dir/deleteProcess.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/deleteProcess.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Luiz Tavares/Documents/algtrab/deleteProcess.c" -o CMakeFiles/untitled.dir/deleteProcess.c.s

CMakeFiles/untitled.dir/updateProcess.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/updateProcess.c.o: ../updateProcess.c
CMakeFiles/untitled.dir/updateProcess.c.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/untitled.dir/updateProcess.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled.dir/updateProcess.c.o -MF CMakeFiles/untitled.dir/updateProcess.c.o.d -o CMakeFiles/untitled.dir/updateProcess.c.o -c "/mnt/c/Users/Luiz Tavares/Documents/algtrab/updateProcess.c"

CMakeFiles/untitled.dir/updateProcess.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/updateProcess.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Luiz Tavares/Documents/algtrab/updateProcess.c" > CMakeFiles/untitled.dir/updateProcess.c.i

CMakeFiles/untitled.dir/updateProcess.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/updateProcess.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Luiz Tavares/Documents/algtrab/updateProcess.c" -o CMakeFiles/untitled.dir/updateProcess.c.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/main.c.o" \
"CMakeFiles/untitled.dir/utils.c.o" \
"CMakeFiles/untitled.dir/readProcess.c.o" \
"CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o" \
"CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o" \
"CMakeFiles/untitled.dir/mangaDataFileManage.c.o" \
"CMakeFiles/untitled.dir/deleteProcess.c.o" \
"CMakeFiles/untitled.dir/updateProcess.c.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/main.c.o
untitled: CMakeFiles/untitled.dir/utils.c.o
untitled: CMakeFiles/untitled.dir/readProcess.c.o
untitled: CMakeFiles/untitled.dir/mangaSecundaryIndexManege.c.o
untitled: CMakeFiles/untitled.dir/mangaPrimaryIndexManage.c.o
untitled: CMakeFiles/untitled.dir/mangaDataFileManage.c.o
untitled: CMakeFiles/untitled.dir/deleteProcess.c.o
untitled: CMakeFiles/untitled.dir/updateProcess.c.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled
.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd "/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Luiz Tavares/Documents/algtrab" "/mnt/c/Users/Luiz Tavares/Documents/algtrab" "/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug" "/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug" "/mnt/c/Users/Luiz Tavares/Documents/algtrab/cmake-build-debug/CMakeFiles/untitled.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

