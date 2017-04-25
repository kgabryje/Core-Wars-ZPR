cmake_minimum_required(VERSION 3.7)
project(client)

include_directories(/usr/local/include/thrift)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include/thrift -std=c++11")

set(SOURCE_FILES ../gen-cpp/MARS.cpp ../gen-cpp/mars_constants.cpp ../gen-cpp/mars_types.cpp main.cpp
        parser/InstructionFactory.cpp parser/RedcodeParser.cpp parser/InstructionData.cpp ServerConnector.cpp
        mars/Instruction.cpp mars/InstructionOperator.cpp parser/ParserException.cpp MainController.cpp
        mars/MarsSimulator.cpp Initializer.cpp)
add_executable(CoreWars ${SOURCE_FILES})
target_link_libraries(CoreWars thrift)
