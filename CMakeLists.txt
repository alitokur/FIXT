cmake_minimum_required(VERSION 3.20)
project(FIXT)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(apps)
