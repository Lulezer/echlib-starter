cmake_minimum_required(VERSION 3.16)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
project(echlib-starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ECHLIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/echlib" CACHE PATH "Path to echlib source tree")

if(NOT EXISTS "${ECHLIB_ROOT}/CMakeLists.txt")
    message(FATAL_ERROR
        "echlib not found at ${ECHLIB_ROOT}\n"
        "Clone with submodules:\n"
        "  git clone --recurse-submodules https://github.com/Lulezer/echlib-starter.git\n"
        "Or set -DECHLIB_ROOT=/path/to/Echlib-Library")
endif()

add_subdirectory("${ECHLIB_ROOT}" "${CMAKE_BINARY_DIR}/echlib")

add_executable(echlib-starter src/main.cpp)
target_link_libraries(echlib-starter PRIVATE echlib)

if(WIN32)
    target_link_libraries(echlib-starter PRIVATE opengl32)
endif()