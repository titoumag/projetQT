# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tmagnin4/CLionProjects/projetQT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tmagnin4/CLionProjects/projetQT/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projet.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/projet.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/projet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projet.dir/flags.make

CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o: projet_autogen/mocs_compilation.cpp
CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o: CMakeFiles/projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o -MF CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o -c /home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/projet_autogen/mocs_compilation.cpp

CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/projet_autogen/mocs_compilation.cpp > CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.i

CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/projet_autogen/mocs_compilation.cpp -o CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.s

CMakeFiles/projet.dir/main.cpp.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/main.cpp.o: /home/tmagnin4/CLionProjects/projetQT/main.cpp
CMakeFiles/projet.dir/main.cpp.o: CMakeFiles/projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/projet.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projet.dir/main.cpp.o -MF CMakeFiles/projet.dir/main.cpp.o.d -o CMakeFiles/projet.dir/main.cpp.o -c /home/tmagnin4/CLionProjects/projetQT/main.cpp

CMakeFiles/projet.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projet.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmagnin4/CLionProjects/projetQT/main.cpp > CMakeFiles/projet.dir/main.cpp.i

CMakeFiles/projet.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projet.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmagnin4/CLionProjects/projetQT/main.cpp -o CMakeFiles/projet.dir/main.cpp.s

CMakeFiles/projet.dir/Windows.cpp.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/Windows.cpp.o: /home/tmagnin4/CLionProjects/projetQT/Windows.cpp
CMakeFiles/projet.dir/Windows.cpp.o: CMakeFiles/projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/projet.dir/Windows.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projet.dir/Windows.cpp.o -MF CMakeFiles/projet.dir/Windows.cpp.o.d -o CMakeFiles/projet.dir/Windows.cpp.o -c /home/tmagnin4/CLionProjects/projetQT/Windows.cpp

CMakeFiles/projet.dir/Windows.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projet.dir/Windows.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmagnin4/CLionProjects/projetQT/Windows.cpp > CMakeFiles/projet.dir/Windows.cpp.i

CMakeFiles/projet.dir/Windows.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projet.dir/Windows.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmagnin4/CLionProjects/projetQT/Windows.cpp -o CMakeFiles/projet.dir/Windows.cpp.s

CMakeFiles/projet.dir/Board.cpp.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/Board.cpp.o: /home/tmagnin4/CLionProjects/projetQT/Board.cpp
CMakeFiles/projet.dir/Board.cpp.o: CMakeFiles/projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/projet.dir/Board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projet.dir/Board.cpp.o -MF CMakeFiles/projet.dir/Board.cpp.o.d -o CMakeFiles/projet.dir/Board.cpp.o -c /home/tmagnin4/CLionProjects/projetQT/Board.cpp

CMakeFiles/projet.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projet.dir/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmagnin4/CLionProjects/projetQT/Board.cpp > CMakeFiles/projet.dir/Board.cpp.i

CMakeFiles/projet.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projet.dir/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmagnin4/CLionProjects/projetQT/Board.cpp -o CMakeFiles/projet.dir/Board.cpp.s

CMakeFiles/projet.dir/Param.cpp.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/Param.cpp.o: /home/tmagnin4/CLionProjects/projetQT/Param.cpp
CMakeFiles/projet.dir/Param.cpp.o: CMakeFiles/projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/projet.dir/Param.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projet.dir/Param.cpp.o -MF CMakeFiles/projet.dir/Param.cpp.o.d -o CMakeFiles/projet.dir/Param.cpp.o -c /home/tmagnin4/CLionProjects/projetQT/Param.cpp

CMakeFiles/projet.dir/Param.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projet.dir/Param.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmagnin4/CLionProjects/projetQT/Param.cpp > CMakeFiles/projet.dir/Param.cpp.i

CMakeFiles/projet.dir/Param.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projet.dir/Param.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmagnin4/CLionProjects/projetQT/Param.cpp -o CMakeFiles/projet.dir/Param.cpp.s

CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o: /home/tmagnin4/CLionProjects/projetQT/reseau/ServeurTcp.cpp
CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o: CMakeFiles/projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o -MF CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o.d -o CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o -c /home/tmagnin4/CLionProjects/projetQT/reseau/ServeurTcp.cpp

CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmagnin4/CLionProjects/projetQT/reseau/ServeurTcp.cpp > CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.i

CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmagnin4/CLionProjects/projetQT/reseau/ServeurTcp.cpp -o CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.s

CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o: /home/tmagnin4/CLionProjects/projetQT/reseau/ClientTcp.cpp
CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o: CMakeFiles/projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o -MF CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o.d -o CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o -c /home/tmagnin4/CLionProjects/projetQT/reseau/ClientTcp.cpp

CMakeFiles/projet.dir/reseau/ClientTcp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projet.dir/reseau/ClientTcp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmagnin4/CLionProjects/projetQT/reseau/ClientTcp.cpp > CMakeFiles/projet.dir/reseau/ClientTcp.cpp.i

CMakeFiles/projet.dir/reseau/ClientTcp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projet.dir/reseau/ClientTcp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmagnin4/CLionProjects/projetQT/reseau/ClientTcp.cpp -o CMakeFiles/projet.dir/reseau/ClientTcp.cpp.s

CMakeFiles/projet.dir/reseau/Reseau.cpp.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/reseau/Reseau.cpp.o: /home/tmagnin4/CLionProjects/projetQT/reseau/Reseau.cpp
CMakeFiles/projet.dir/reseau/Reseau.cpp.o: CMakeFiles/projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/projet.dir/reseau/Reseau.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projet.dir/reseau/Reseau.cpp.o -MF CMakeFiles/projet.dir/reseau/Reseau.cpp.o.d -o CMakeFiles/projet.dir/reseau/Reseau.cpp.o -c /home/tmagnin4/CLionProjects/projetQT/reseau/Reseau.cpp

CMakeFiles/projet.dir/reseau/Reseau.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projet.dir/reseau/Reseau.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmagnin4/CLionProjects/projetQT/reseau/Reseau.cpp > CMakeFiles/projet.dir/reseau/Reseau.cpp.i

CMakeFiles/projet.dir/reseau/Reseau.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projet.dir/reseau/Reseau.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmagnin4/CLionProjects/projetQT/reseau/Reseau.cpp -o CMakeFiles/projet.dir/reseau/Reseau.cpp.s

# Object files for target projet
projet_OBJECTS = \
"CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/projet.dir/main.cpp.o" \
"CMakeFiles/projet.dir/Windows.cpp.o" \
"CMakeFiles/projet.dir/Board.cpp.o" \
"CMakeFiles/projet.dir/Param.cpp.o" \
"CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o" \
"CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o" \
"CMakeFiles/projet.dir/reseau/Reseau.cpp.o"

# External object files for target projet
projet_EXTERNAL_OBJECTS =

projet: CMakeFiles/projet.dir/projet_autogen/mocs_compilation.cpp.o
projet: CMakeFiles/projet.dir/main.cpp.o
projet: CMakeFiles/projet.dir/Windows.cpp.o
projet: CMakeFiles/projet.dir/Board.cpp.o
projet: CMakeFiles/projet.dir/Param.cpp.o
projet: CMakeFiles/projet.dir/reseau/ServeurTcp.cpp.o
projet: CMakeFiles/projet.dir/reseau/ClientTcp.cpp.o
projet: CMakeFiles/projet.dir/reseau/Reseau.cpp.o
projet: CMakeFiles/projet.dir/build.make
projet: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
projet: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
projet: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
projet: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
projet: CMakeFiles/projet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable projet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projet.dir/build: projet
.PHONY : CMakeFiles/projet.dir/build

CMakeFiles/projet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projet.dir/clean

CMakeFiles/projet.dir/depend:
	cd /home/tmagnin4/CLionProjects/projetQT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tmagnin4/CLionProjects/projetQT /home/tmagnin4/CLionProjects/projetQT /home/tmagnin4/CLionProjects/projetQT/cmake-build-debug /home/tmagnin4/CLionProjects/projetQT/cmake-build-debug /home/tmagnin4/CLionProjects/projetQT/cmake-build-debug/CMakeFiles/projet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projet.dir/depend

