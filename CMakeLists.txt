cmake_minimum_required(VERSION 3.15)
project(kode CXX)

if (APPLE)
    message(FATAL_ERROR "OSX is currently not supported")
endif ()

if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND
        NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND
        NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(FATAL_ERROR "Only MSVC, GCC and Clang compilers are currently supported")
endif ()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

include(ProjectWarnings)
include(Dependencies)
include(DockerBuild)

add_subdirectory(external)
add_subdirectory(src)

if (NOT DISABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif ()
