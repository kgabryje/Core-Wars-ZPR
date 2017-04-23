cmake_minimum_required(VERSION 3.7)
project(server)

#add_subdirectory(logic)
#add_subdirectory(gen-cpp)

include_directories(/usr/local/include/thrift)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include/thrift -std=c++11")
set(APP_LOGIC ./logic)

include_directories(.)
add_executable(server MARS.cpp mars_constants.cpp mars_types.cpp server.cpp)

target_link_libraries(server thrift)