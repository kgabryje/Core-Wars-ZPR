cmake_minimum_required(VERSION 3.7)
project(Core-Wars-ZPR)

include_directories(.)


find_path(THRIFT_FOUND_HEADERS thrift PATHS ${THRIFT_INCLUDE_DIR})
MESSAGE("Thrift found headers: ${THRIFT_FOUND_HEADERS}")
include_directories(${THRIFT_FOUND_HEADERS})


add_subdirectory(logic)
add_subdirectory(server)