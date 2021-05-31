# CMakeList.txt : CMake project for Casino_plus, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
FILE(GLOB_RECURSE SrcFiles "*.cpp" "*.h")
list(REMOVE_ITEM SrcFiles "Casino_plus_py.cpp")
add_library (Casino_plus STATIC ${SrcFiles})
