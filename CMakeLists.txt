cmake_minimum_required(VERSION 3.12)
project(MyProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall -Werror -Wno-unused -ldl -lpthread -fPIC")

# Find all source files
file(GLOB_RECURSE SRCS *.cpp)
list(FILTER SRCS EXCLUDE REGEX "server.cpp|client.cpp")

# Find all header files
file(GLOB_RECURSE INCLUDES *.h)

# Add server executable
set(SRC_SERVER server.cpp)
add_executable(server ${SRC_SERVER} ${SRCS} ${INCLUDES})

# Add client executable
set(SRC_CLIENT client.cpp)
add_executable(client ${SRC_CLIENT} ${SRCS} ${INCLUDES})

# Remove the 'main' function from the source files
set_target_properties(server PROPERTIES
    COMPILE_DEFINITIONS "IS_SERVER"
)
set_target_properties(client PROPERTIES
    COMPILE_DEFINITIONS "IS_CLIENT"
)

# Clean target
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -P clean-all.cmake
)