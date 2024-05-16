cmake_minimum_required(VERSION 3.12)
project(c_books_and_projects C CXX)

# Set the C and C++ standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_CLANG_TIDY "Enable clang-tidy" ON)

if (ENABLE_CLANG_TIDY)

# Find clang-tidy executable
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    # Set the command to run clang-tidy
    set(CMAKE_C_CLANG_TIDY "${CLANG_TIDY_EXE};-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy;-header-filter=${CMAKE_SOURCE_DIR}/*")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy;-header-filter=${CMAKE_SOURCE_DIR}/*")
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
else()
    message(WARNING "clang-tidy executable not found")
endif()

endif()
add_compile_options(-pg -fno-omit-frame-pointer)

add_subdirectory(C-Primer-Plus)
add_subdirectory(pathfinding-maze-solver)
add_subdirectory(sorting_algos)
add_subdirectory(beautiful-c++-14-stl-algorithms)
