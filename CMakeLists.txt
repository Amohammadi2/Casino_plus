﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Casino_plus")

# Include sub-projects.
add_subdirectory ("Casino_plus")
add_subdirectory ("PyBinding")
add_subdirectory ("Tests")
include_directories("Casino_plus/include")
