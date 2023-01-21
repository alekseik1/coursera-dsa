cmake_policy(SET CMP0048 NEW)
project(DSA)
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all -O2 -Wall -Werror -Wsign-compare"
        CACHE STRING "Compiler flags in asan build"
        FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -Wall -Werror -Wsign-compare"
        CACHE STRING "Compiler flags in release build"
        FORCE)

# Catch2 installation
Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_subdirectory(algorithmic-toolbox)