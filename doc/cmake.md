# CMake

## Overview

CMake is an open-source, cross-platform family of tools designed to build, test and package software.

## cmake

### Synopsis

### Description

The **cmake** executable is the command-line interface of the cross-platform buildsystem generator CMake.

To build a software project with CMake, Generate a Project Buildsystem.
Optionally use **cmake** to Build a Project, Install a Project or just run the corresponding build tool (e.g. make) directly.
**cmake** can also be used to View Help.

The other actions are meant for use by software developers writing scripts in the CMake language to support their builds.

### Introduction to CMake Buildsystems

A *buildsystem* describes how to build a project's executables and libraries from its source code using a build tool to automate the process.
For example, a buildsystem may be a Makefile for use with a command-line make tool or a project file for an Integrated Development Environment (IDE).
In order to avoid maintaining multiple such buildsystems, a project may specify its buildsystem abstractly using files written in the **CMake language**.
From these files CMake generates a preferred buildsystem locally for each user through a backend called a *generator*.

To generate a buildsystem with CMake, the following must be selected:
- Source Tree
The top-level directory containing source files provided by the project.
The project specifies its buildsystem using files as described in the cmake-language(7) manual, starting with a top-level file named **CMakeLists.txt**.
These files specify build targets and their dependencies as described in the cmake-buildsystem(7) manual.

- Build Tree
The top-level directory in which buildsystem files and build output artifacts (e.g. executables and libraries) are to be stored.
CMake will write a **CMakeCache.txt** file to identify the directory as a build tree and store persistent information such as buildsystem configuration options.
To maintain a pristine source tree, perform an *out-of-source* build by using a separate dedicated build tree.
An *in-source build* in which the build tree is placed in the same directory as the source tree is also supported, but discouraged.

- Generator
This chooses the kind of buildsystem to generate.
See the cmake-generators(7) manual for documentation of all generators.
Run `cmake --help` to see a list of generators available locally.
Optionally use the `-G` option below to specify a generator, or simply accept the default CMake chooses for the current platform.
When using one of the Command-Line Build Tool Generators CMake expects that the environment needed by the compiler toolchain is already configured in the shell.
When using one of the IDE Build Tool Generators, no particular environment is needed.

### Generate a Project Buildsystem
