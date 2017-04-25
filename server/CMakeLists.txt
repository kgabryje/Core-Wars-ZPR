cmake_minimum_required(VERSION 3.7)
project(server)

include_directories(/usr/local/include/thrift)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include/thrift -std=c++11")

add_executable(Server ../gen-cpp/MARS.cpp ../gen-cpp/mars_constants.cpp ../gen-cpp/mars_types.cpp server.cpp)

target_link_libraries(Server thrift)
