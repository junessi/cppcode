set(BINARY TaskFlowTest)

file(GLOB SOURCES TaskFlowTest.cpp)
add_executable(${BINARY} ${SOURCES})

add_custom_command(TARGET ${BINARY}
                   COMMENT "Run unittest ${BINARY}"
                   POST_BUILD
                   COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
