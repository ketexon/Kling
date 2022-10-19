cmake_minimum_required (VERSION 3.25)

project (PhonemicAnalysis)

add_subdirectory(extern/frozen)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)
add_subdirectory (src)
