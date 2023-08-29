cmake_minimum_required(VERSION 3.10)
project(jrlcServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(jrlcServer TCPServer.cpp)

target_include_directories(jrlcServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
