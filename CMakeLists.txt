cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_COMPILER /usr/bin/x86_64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/x86_64-linux-gnu-g++)

project(cppcode)
set(GOOGLETEST_VERSION 1.10.0)

set(CMAKE_CXX_STANDARD 14)
enable_testing()
include(CTest)

include_directories(src)
include_directories(test)
include_directories(lib/googletest/include/src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
# add_subdirectory(lib/googlemock)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

