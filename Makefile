# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /home/dylan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dylan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/dylan/School/Computer Networks/cpp-chat-client"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/dylan/School/Computer Networks/cpp-chat-client"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/dylan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/dylan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/dylan/School/Computer Networks/cpp-chat-client/CMakeFiles" "/home/dylan/School/Computer Networks/cpp-chat-client/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/dylan/School/Computer Networks/cpp-chat-client/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named cpp-chat-client

# Build rule for target.
cpp-chat-client: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cpp-chat-client
.PHONY : cpp-chat-client

# fast build rule for target.
cpp-chat-client/fast:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/build
.PHONY : cpp-chat-client/fast

Application.o: Application.cpp.o

.PHONY : Application.o

# target to build an object file
Application.cpp.o:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Application.cpp.o
.PHONY : Application.cpp.o

Application.i: Application.cpp.i

.PHONY : Application.i

# target to preprocess a source file
Application.cpp.i:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Application.cpp.i
.PHONY : Application.cpp.i

Application.s: Application.cpp.s

.PHONY : Application.s

# target to generate assembly for a file
Application.cpp.s:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Application.cpp.s
.PHONY : Application.cpp.s

CircularLineBuffer.o: CircularLineBuffer.cpp.o

.PHONY : CircularLineBuffer.o

# target to build an object file
CircularLineBuffer.cpp.o:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/CircularLineBuffer.cpp.o
.PHONY : CircularLineBuffer.cpp.o

CircularLineBuffer.i: CircularLineBuffer.cpp.i

.PHONY : CircularLineBuffer.i

# target to preprocess a source file
CircularLineBuffer.cpp.i:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/CircularLineBuffer.cpp.i
.PHONY : CircularLineBuffer.cpp.i

CircularLineBuffer.s: CircularLineBuffer.cpp.s

.PHONY : CircularLineBuffer.s

# target to generate assembly for a file
CircularLineBuffer.cpp.s:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/CircularLineBuffer.cpp.s
.PHONY : CircularLineBuffer.cpp.s

Client.o: Client.cpp.o

.PHONY : Client.o

# target to build an object file
Client.cpp.o:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Client.cpp.o
.PHONY : Client.cpp.o

Client.i: Client.cpp.i

.PHONY : Client.i

# target to preprocess a source file
Client.cpp.i:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Client.cpp.i
.PHONY : Client.cpp.i

Client.s: Client.cpp.s

.PHONY : Client.s

# target to generate assembly for a file
Client.cpp.s:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Client.cpp.s
.PHONY : Client.cpp.s

ClientHandler.o: ClientHandler.cpp.o

.PHONY : ClientHandler.o

# target to build an object file
ClientHandler.cpp.o:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/ClientHandler.cpp.o
.PHONY : ClientHandler.cpp.o

ClientHandler.i: ClientHandler.cpp.i

.PHONY : ClientHandler.i

# target to preprocess a source file
ClientHandler.cpp.i:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/ClientHandler.cpp.i
.PHONY : ClientHandler.cpp.i

ClientHandler.s: ClientHandler.cpp.s

.PHONY : ClientHandler.s

# target to generate assembly for a file
ClientHandler.cpp.s:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/ClientHandler.cpp.s
.PHONY : ClientHandler.cpp.s

Server.o: Server.cpp.o

.PHONY : Server.o

# target to build an object file
Server.cpp.o:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Server.cpp.o
.PHONY : Server.cpp.o

Server.i: Server.cpp.i

.PHONY : Server.i

# target to preprocess a source file
Server.cpp.i:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Server.cpp.i
.PHONY : Server.cpp.i

Server.s: Server.cpp.s

.PHONY : Server.s

# target to generate assembly for a file
Server.cpp.s:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/Server.cpp.s
.PHONY : Server.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/main.cpp.s
.PHONY : main.cpp.s

vusocket.o: vusocket.cpp.o

.PHONY : vusocket.o

# target to build an object file
vusocket.cpp.o:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/vusocket.cpp.o
.PHONY : vusocket.cpp.o

vusocket.i: vusocket.cpp.i

.PHONY : vusocket.i

# target to preprocess a source file
vusocket.cpp.i:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/vusocket.cpp.i
.PHONY : vusocket.cpp.i

vusocket.s: vusocket.cpp.s

.PHONY : vusocket.s

# target to generate assembly for a file
vusocket.cpp.s:
	$(MAKE) -f CMakeFiles/cpp-chat-client.dir/build.make CMakeFiles/cpp-chat-client.dir/vusocket.cpp.s
.PHONY : vusocket.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... cpp-chat-client"
	@echo "... edit_cache"
	@echo "... Application.o"
	@echo "... Application.i"
	@echo "... Application.s"
	@echo "... CircularLineBuffer.o"
	@echo "... CircularLineBuffer.i"
	@echo "... CircularLineBuffer.s"
	@echo "... Client.o"
	@echo "... Client.i"
	@echo "... Client.s"
	@echo "... ClientHandler.o"
	@echo "... ClientHandler.i"
	@echo "... ClientHandler.s"
	@echo "... Server.o"
	@echo "... Server.i"
	@echo "... Server.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... vusocket.o"
	@echo "... vusocket.i"
	@echo "... vusocket.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

