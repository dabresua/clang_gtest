cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_COMPILER "clang++")
project(sonar_scanner_example)

# Add compile flags to instrument the binaries for coverage
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping -O0 -g")
set(CMAKE_CXX_STANDARD 17)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.13.0)
FetchContent_GetProperties(googletest)
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

include_directories(lib)

add_executable(coverage_test lib/lib.cpp test/test1.cpp test/test2.cpp test/main.cpp)
target_link_libraries(coverage_test gtest_main gmock_main)
