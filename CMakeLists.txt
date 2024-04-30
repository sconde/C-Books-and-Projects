cmake_minimum_required(VERSION 3.12)
project(c_books_and_projects C CXX)

# Set the C standard to C11
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(C-Primer-Plus)
