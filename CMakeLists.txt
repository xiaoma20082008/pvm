cmake_minimum_required(VERSION 3.16)
project(pvm LANGUAGES C CXX ASM VERSION 1.0.0)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -std=c++17 -Wall -Werror -fno-rtti -fno-exceptions")
set(CMAKE_CXX_FLAGS_RELEASE " -O1 -std=c++17 -Wall -Werror -fno-rtti -fno-exceptions")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

enable_testing()

add_subdirectory(external)
add_subdirectory(src/main)
add_subdirectory(src/test)