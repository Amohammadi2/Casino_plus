# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Casino_plus")

# Include sub-projects.
add_subdirectory ("Casino_plus")
add_subdirectory ("Dependencies/pybind11")
add_subdirectory ("PyBinding")

pybind11_add_module(CasinoPlus 
 "PyBinding/CasinoPlus.cpp"
 "Casino_plus/Casino_plus.cpp"
 "Casino_plus/include/Casino_plus.h"
)