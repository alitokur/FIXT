cmake_minimum_required(VERSION 3.20)
project(fix_tcp_server)
set (CMAKE_CXX_STANDARD 11)
add_executable(run_server main.cpp FIXServer.cpp)
