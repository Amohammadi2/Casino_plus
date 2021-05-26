cmake_minimum_required(VERSION 3.8)

FILE(GLOB_RECURSE SourceFiles
 "../Casino_plus/include/*.h"
 "../Casino_plus/*.cpp"
)

include(FetchContent)

FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.6.2
)


FetchContent_GetProperties(pybind11)
if(NOT pybind11_POPULATED)
  FetchContent_Populate(pybind11)
  add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
endif()

pybind11_add_module(CasinoPlus 
 "CasinoPlus.cpp"
 ${SourceFiles}
)

target_include_directories(CasinoPlus
  PUBLIC "../Casino_plus/include"
)