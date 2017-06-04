cmake_minimum_required(VERSION 3.7)
project(client)
link_directories(/usr/local/lib/)
include_directories(/usr/local/include/thrift)
set(SOURCE_FILES ../gen-cpp/MARS.cpp ../gen-cpp/mars_constants.cpp ../gen-cpp/mars_types.cpp main.cpp
        parser/InstructionDataExtractor.cpp parser/InstructionAddress.cpp parser/InstructionCreator.cpp parser/AddressCreator.cpp
        parser/RawCodeFormatter.cpp parser/InstructionParser.cpp parser/InstructionFactory.cpp parser/RedcodeParser.cpp
        parser/InstructionData.cpp ServerConnector.cpp parser/ModifierFactory.cpp parser/IndirectInstructionModifier.cpp
        parser/ImmidiateInstructionModifier.cpp parser/DirectInstructionModifier.cpp parser/InstructionModifier.cpp
        mars/Instruction.cpp parser/ParserException.cpp MainController.cpp
        mars/MarsSimulator.cpp Initializer.cpp Player.cpp Player.h PlayerInfo.cpp PlayerInfo.h Warrior.cpp Warrior.h PlayerCreator.cpp PlayerCreator.h view/ViewInput.cpp view/ViewInput.h MarsResult.cpp MarsResult.h mars/DatInstruction.cpp mars/DatInstruction.h mars/MovInstruction.cpp mars/MovInstruction.h)
add_executable(CoreWars ${SOURCE_FILES})

target_link_libraries(CoreWars thrift boost_regex)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include/thrift -std=c++11")
set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib")

