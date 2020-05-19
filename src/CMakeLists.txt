set(BINARY ${CMAKE_PROJECT_NAME})

add_subdirectory(cppcode)

set(SOURCES "main.cpp" ${SOURCES})

find_package( Threads )

add_executable(${BINARY}_run ${SOURCES})
target_link_libraries(${BINARY}_run ${CMAKE_THREAD_LIBS_INIT} )

add_library(${BINARY}_lib STATIC ${SOURCES})

