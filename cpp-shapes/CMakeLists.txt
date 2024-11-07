# Set the name of the project and target:
SET(TARGET "shapes")

# Declare all source files the target consists of. Here, this is only
SET(TARGET_SRC shapes.cc)

CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${TARGET})
add_executable(${TARGET} ${TARGET_SRC})
