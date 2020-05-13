cmake_minimum_required(VERSION 3.10)

project(cppcode)
set(GOOGLETEST_VERSION 1.10.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(test)
include_directories(lib/googletest/include/src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
# add_subdirectory(lib/googlemock)
