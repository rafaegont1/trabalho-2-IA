# Set the cmake minimum version
cmake_minimum_required(VERSION 3.5)

# Define the project name
project(uninformed_search)

# Generate symbols for IDE indexer
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to C11
set(CMAKE_C_STANDARD 11)

# Adding macro definitions for debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG -DA_STAR -DGBS)
endif()

# Include headers from the 'include' directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create A_STAR executable
add_executable(a_star
    src/main.c
    src/util.c
    src/matrix.c
    src/p_queue.c
)
target_compile_definitions(a_star PRIVATE A_STAR)

# Create A_STAR executable
add_executable(gbs
    src/main.c
    src/util.c
    src/matrix.c
    src/p_queue.c
)
target_compile_definitions(gbs PRIVATE GBS)

# Add compilation flags (apply to both executables)
target_compile_options(a_star PRIVATE -Wall -Wextra)
target_compile_options(gbs PRIVATE -Wall -Wextra)

# If you want to ensure that the executables are built in debug/release mode
# you can add build type specific options:
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     target_compile_options(dfs PRIVATE -g)
#     target_compile_options(bfs PRIVATE -g)
# endif()
