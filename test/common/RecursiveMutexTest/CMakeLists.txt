set(BINARY RecursiveMutexTest)

file(GLOB SOURCES ${BINARY}.cpp)
add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PRIVATE ${CMAKE_PROJECT_NAME}_lib gtest)
add_custom_target(${BINARY}.run COMMAND ${BINARY})
add_test(${BINARY} ${BINARY})
