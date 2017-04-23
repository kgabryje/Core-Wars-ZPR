cmake_minimum_required(VERSION 3.7)
project(Core-Wars-ZPR)

#add_subdirectory(logic)
add_subdirectory(gen-cpp)

include_directories(/usr/local/include/thrift)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include/thrift -std=c++11")
set(APP_LOGIC ./logic)

include_directories(.)
#add_executable(server gen-cpp/MARS.cpp gen-cpp/mars_constants.cpp gen-cpp/mars_types.cpp gen-cpp/server.cpp)

set(SOURCE_FILES gen-cpp/MARS.cpp gen-cpp/mars_constants.cpp gen-cpp/mars_types.cpp logic/main.cpp logic/parser/InstructionFactory.cpp logic/parser/InstructionFactory.h logic/parser/RedcodeParser.cpp logic/parser/RedcodeParser.h logic/parser/InstructionData.cpp logic/parser/InstructionData.h logic/ServerConnector.cpp logic/ServerConnector.h logic/mars/Instruction.cpp logic/mars/Instruction.h logic/mars/InstructionOperator.cpp logic/mars/InstructionOperator.h logic/parser/ParserException.cpp logic/parser/ParserException.h logic/MainController.cpp logic/MainController.h logic/mars/MarsSimulator.cpp logic/mars/MarsSimulator.h logic/Initializer.cpp logic/Initializer.h)
add_executable(Core-Wars-ZPR ${SOURCE_FILES})
target_link_libraries(Core-Wars-ZPR thrift)