cmake_minimum_required(VERSION 3.0)
project(linux-shell)

set(CMAKE_CXX_STANDARD 17)

add_executable(linux-shell main.cpp commands.cpp)