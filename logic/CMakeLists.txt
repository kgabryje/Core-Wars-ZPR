cmake_minimum_required(VERSION 3.7)
project(client)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(THRIFT_ROOT "/usr/local/")
SET(THRIFT_INCLUDE_DIR "/usr/local/include")
SET(THRIFT_LIB_DIR "/usr/local/lib")

find_library(THRIFT_FOUND_LIB thrift PATHS ${THRIFT_LIB_DIR})
MESSAGE("Found Thrift lib: ${THRIFT_FOUND_LIB}")

find_path(THRIFT_FOUND_HEADERS thrift PATHS ${THRIFT_INCLUDE_DIR})
MESSAGE("Found Thrift headers: ${THRIFT_FOUND_HEADERS}")

include_directories(${THRIFT_FOUND_HEADERS})
link_directories(${THRIFT_FOUND_HEADERS})
link_directories(${THRIFT_FOUND_LIB})

#SET (BOOST_INCLUDEDIR "c:\\Users\\Antek\\libs\\boost_1_64_0\\boost")
#SET (BOOST_LIBRARYDIR "c:\\Users\\Antek\\libs\\boost_1_64_0\\boost\\libs")

find_package(Boost 1.64.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARIES})

set(SOURCE_FILES ../gen-cpp/MARS.cpp ../gen-cpp/mars_constants.cpp ../gen-cpp/mars_types.cpp main.cpp
        parser/OperationFactory.cpp parser/RedcodeParser.cpp parser/InstructionData.cpp ServerConnector.cpp
        mars/OperationParamsMixed.cpp mars/OperationParamsMixed.h mars/OperationParams.cpp mars/OperationParams.h mars/MovOperation.cpp mars/DatOperation.h mars/MovOperation.h mars/DatOperation.cpp mars/DatOperation.h mars/MarsOperation.cpp mars/MarsOperation.h mars/Instruction.cpp parser/ParserException.cpp MainController.cpp
        mars/MarsSimulator.cpp Initializer.cpp Player.cpp Player.h PlayerInfo.cpp PlayerInfo.h Warrior.cpp
        Warrior.h PlayerCreator.cpp PlayerCreator.h view/ViewInput.cpp view/ViewInput.h MarsResult.cpp MarsResult.h

        parser/RawCodeFormatter.cpp parser/RawCodeFormatter.h
        parser/InstructionParser.cpp parser/InstructionParser.h  parser/InstructionDataExtractor.cpp parser/InstructionDataExtractor.h  CoreWarsConstants.h parser/InstructionCreator.cpp parser/InstructionCreator.h parser/InstructionModifier.cpp parser/InstructionModifier.h parser/ModifierFactory.cpp parser/ModifierFactory.h parser/InstructionModifierCreator.cpp parser/InstructionModifierCreator.h parser/IndirectInstructionModifier.cpp parser/IndirectInstructionModifier.h parser/ImmediateInstructionModifier.cpp parser/ImmediateInstructionModifier.h parser/DirectInstructionModifier.cpp parser/DirectInstructionModifier.h  mars/ProcessManager.cpp mars/ProcessManager.h mars/ProcessAction.cpp mars/ProcessAction.h mars/ProcessActionContinue.cpp mars/ProcessActionContinue.h mars/ProcessActionRemove.cpp mars/ProcessActionRemove.h mars/ProcessActionBranch.cpp mars/ProcessActionBranch.h mars/MemoryIndex.cpp mars/MemoryIndex.h mars/OperationParamsInstructions.cpp mars/OperationParamsInstructions.h mars/AddOperation.cpp mars/AddOperation.h mars/JmpOperation.cpp mars/JmpOperation.h mars/ProcessActionJump.cpp mars/ProcessActionJump.h mars/MarsEngine.cpp mars/MarsEngine.h)

add_executable(CoreWars ${SOURCE_FILES})

target_include_directories(CoreWars SYSTEM PUBLIC ${THRIFT_FOUND_HEADERS})
target_link_libraries(CoreWars LINK_PUBLIC ${THRIFT_FOUND_LIB} ${Boost_LIBRARIES})
