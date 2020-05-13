set(BINARY ${CMAKE_PROJECT_NAME})

add_subdirectory(binary_search)

set(SOURCES "main.cpp" ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

