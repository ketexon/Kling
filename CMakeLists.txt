cmake_minimum_required (VERSION 3.25)

project (Kling)

include(CTest)
add_subdirectory(extern/catch2)
include(Catch)

add_subdirectory(extern/frozen)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)
add_subdirectory (src)
add_subdirectory (tests)
