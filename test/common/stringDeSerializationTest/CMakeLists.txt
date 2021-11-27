set(BINARY stringDeSerializationTest)

file(GLOB SOURCES stringDeSerializationTest.hpp stringDeSerializationTest.cpp)
add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
add_test(${BINARY} ${BINARY})
