# Set the name of the project and target:
SET(TARGET "main")

# Declare all source files the target consists of.
SET(TARGET_SRC main.cc)

# Usually, you will not need to modify anything beyond this point...

cmake_minimum_required(VERSION 3.2)

project(${TARGET})

find_package(MPI REQUIRED)
add_definitions(-DOMPI_SKIP_MPICXX)
add_executable(${TARGET} ${TARGET_SRC})
target_link_libraries(${TARGET} PRIVATE MPI::MPI_CXX)
