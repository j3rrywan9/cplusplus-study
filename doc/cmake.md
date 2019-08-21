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
From these files CMake generates a preferred buildsystem locally for each user through a backend called a generator.
