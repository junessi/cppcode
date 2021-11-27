set(BINARY heapSortTest)

file(GLOB SOURCES heapSortTest.hpp heapSortTest.cpp)
add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
add_test(${BINARY} ${BINARY})
