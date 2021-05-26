cmake_minimum_required (VERSION 3.8)

FILE(GLOB_RECURSE SourceFiles
  "../Casino_plus/*.cpp"
  "../Casino_plus/*.h"
  "*.cpp"
  "*.h"
)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

enable_testing()

add_executable(AlgoTest ${SourceFiles})

target_link_libraries(AlgoTest
  Casino_plus 
  gtest_main
)

target_include_directories(AlgoTest
  PUBLIC "../Casino_plus/include"
)

include(GoogleTest)
gtest_discover_tests(AlgoTest)