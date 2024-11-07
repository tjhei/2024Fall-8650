# Set the name of the project and target:
SET(TARGET "threads-mutex")

# Declare all source files the target consists of. Here, this is only
SET(TARGET_SRC main.cc)

CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${TARGET})
add_executable(${TARGET} ${TARGET_SRC})

# require multithreading
find_package(Threads)
target_link_libraries(${TARGET} Threads::Threads)
