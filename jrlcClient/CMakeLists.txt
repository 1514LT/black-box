cmake_minimum_required(VERSION 3.10)
project(jrlcClient)

set(CMAKE_CXX_STANDARD 11)

add_executable(jrlcClient TCPClient.cpp)


target_include_directories(jrlcClient PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

