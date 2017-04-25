cmake_minimum_required(VERSION 3.7)
project(Core-Wars-ZPR)

set(CMAKE_CXX_STANDARD 11)

set(APP_LOGIC ./logic)

include_directories(.)

set(SOURCE_FILES  logic/main.cpp logic/parser/InstructionFactory.cpp logic/parser/InstructionFactory.h logic/parser/RedcodeParser.cpp logic/parser/RedcodeParser.h logic/parser/InstructionData.cpp logic/parser/InstructionData.h logic/ServerConnector.cpp logic/ServerConnector.h logic/mars/Instruction.cpp logic/mars/Instruction.h logic/mars/InstructionOperator.cpp logic/mars/InstructionOperator.h logic/parser/ParserException.cpp logic/parser/ParserException.h logic/MainController.cpp logic/MainController.h logic/mars/MarsSimulator.cpp logic/mars/MarsSimulator.h logic/Initializer.cpp logic/Initializer.h logic/view/ViewInput.cpp logic/view/ViewInput.h logic/Player.cpp logic/Player.h logic/PlayerInfo.cpp logic/PlayerInfo.h logic/PlayerCreator.cpp logic/PlayerCreator.h logic/Warrior.cpp logic/Warrior.h logic/MarsResult.cpp logic/MarsResult.h)
add_executable(Core-Wars-ZPR ${SOURCE_FILES})


set(TEST_FILES catch_config.cpp logic/parser/InstructionFactoryTest.cpp logic/parser/InstructionFactory.cpp logic/parser/InstructionFactory.h logic/parser/RedcodeParser.cpp logic/parser/RedcodeParser.h logic/parser/InstructionData.cpp logic/parser/InstructionData.h logic/ServerConnector.cpp logic/ServerConnector.h logic/mars/Instruction.cpp logic/mars/Instruction.h logic/mars/InstructionOperator.cpp logic/mars/InstructionOperator.h logic/parser/ParserException.cpp logic/parser/ParserException.h logic/MainController.cpp logic/MainController.h logic/mars/MarsSimulator.cpp logic/mars/MarsSimulator.h logic/Initializer.cpp logic/Initializer.h logic/view/ViewInput.cpp logic/view/ViewInput.h logic/Player.cpp logic/Player.h logic/PlayerInfo.cpp logic/PlayerInfo.h logic/PlayerCreator.cpp logic/PlayerCreator.h logic/Warrior.cpp logic/Warrior.h logic/MarsResult.cpp logic/MarsResult.h)
add_executable(Core-Wars-Test_Suite ${TEST_FILES})