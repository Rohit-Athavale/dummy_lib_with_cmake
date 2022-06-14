Dummy Library with C++ Application and C-style Wrapper
========================================================

```
  _____  _    _ __  __ __  ____     __
 |  __ \| |  | |  \/  |  \/  \ \   / /
 | |  | | |  | | \  / | \  / |\ \_/ / 
 | |  | | |  | | |\/| | |\/| | \   /  
 | |__| | |__| | |  | | |  | |  | |   
 |_____/ \____/|_|  |_|_|  |_|  |_|   

```                                   
                                      

Table of Contents
-------------------------------------------
* [Design Goals](#design-goals)
* [Why bother ?](#why-bother?)


Design Goals
------------------------
This dummy library is being used an example for the following

	- Using CMake to build a shared library (dummyl)
	- Compiling and linking a C++ Application that uses the dummyl library
	- Creation of C-style wrappers for the C++ library
	- Usage of the C-wrappers in a pure C application
	- Cross Platform Support for
		+ Windows (Windows10) using MS Visual Studio 2022
		+ Linux support using GCC10 and Clang-14

Why bother?
------------------------
If you want a quick skeleton for the following

	* Building a C++ Application that uses a your own C++ Library
	* Building a C-style wrapper for your C++ Library
	* Building a C-style application for your C-style wrapper
	* Examples of enabling cross-platform support for through Cmake
		+ Windows
		+ Linux
