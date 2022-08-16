cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

add_subdirectory(library)

# add the executable
add_executable(Tutorial prog.cpp)

# link the executable
target_link_libraries(Tutorial 
    PUBLIC 
        library
)

# add the binary tree to the search path for include files
# so that we will find file.hpp
target_include_directories(Tutorial 
    PUBLIC
        "${PROJECT_SOURCE_DIR}/library"
)