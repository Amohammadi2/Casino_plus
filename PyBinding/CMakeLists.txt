cmake_minimum_required(VERSION 3.8)

FILE(GLOB_RECURSE SourceFiles
 "../Casino_plus/include/*.h"
 "../Casino_plus/*.cpp"
)


pybind11_add_module(CasinoPlus 
 "CasinoPlus.cpp"
 ${SourceFiles}
)