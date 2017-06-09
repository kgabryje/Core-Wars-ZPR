#include <logic/mars/MarsEngine.h>
#include <logic/parser/RedcodeParser.h>
#include "test_cases/catch.hpp"

SCENARIO("MarsEngineTest") {
    WHEN("Default constructor is fired") {
        MarsEngine mars;
        REQUIRE(mars.getMemoryArray().size() == MARSConstants::MEMORY_ARRAY_SIZE);
        const std::vector<Instruction> memory = mars.getMemoryArray();
        THEN("vector of proper size is created") {
            REQUIRE(memory.size() == MARSConstants::MEMORY_ARRAY_SIZE);

        }
        AND_THEN("vector is populated with DATS 0,0") {
            bool success = true;
            for (Instruction i : memory)
                if (i.getOperation()->getOpCode() != ParserConstants::INSTR_CODE_DAT) {
                    success = false;
                    break;
                }
            REQUIRE(success);
        }
        WHEN("Warrior code (k lines) is inserted in the middle part of memory array") {
            int beginningAddress = 12;
            std::string userInput = "MOV #0 \n"
                    "JMP $5, @2\n"
                    "MOV #-23,8";
            std::vector<Instruction> parsed = RedcodeParser::parse(userInput);
            mars.enterWarrior(beginningAddress, parsed);
            THEN("Warrior starts from beginning address and it's code continues for next k lines,"
                         "rest of the memory behaves same as before insert") {
                bool success = true;
                int counter = -1;
                for (Instruction i : mars.getMemoryArray()) {
                    counter++;
                    if (counter == 12) {
                        REQUIRE(i.getOperation()->getOpCode() == "MOV");
                        continue;
                    }
                    if (counter == 13) {
                        REQUIRE(i.getOperation()->getOpCode() == "JMP");
                        continue;
                    }
                    if (counter == 14) {
                        REQUIRE(i.getOperation()->getOpCode() == "MOV");
                        continue;
                    }
                    if (i.getOperation()->getOpCode() != ParserConstants::INSTR_CODE_DAT) {
                        success = false;
                        break;
                    }
                }
                REQUIRE(success);
            }
            AND_WHEN("Warrior code (k lines) is inserted near the edge of the memory array") {
                int beginningAddress = MARSConstants::MEMORY_ARRAY_SIZE - 2;
                std::string userInput = "MOV #0 \n"
                        "JMP $5, @2\n"
                        "MOV #-23,8\n"
                        "JMP #-23,8\n";
                std::vector<Instruction> parsed = RedcodeParser::parse(userInput);
                mars.enterWarrior(beginningAddress, parsed);
                THEN("Warrior occupies the end and the beginning of the memory array, rest of the memory stays as before insert") {
                    bool success = true;
                    int counter = -1;
                    for (Instruction i : mars.getMemoryArray()) {
                        counter++;
                        if (counter == 0) {
                            REQUIRE(i.getOperation()->getOpCode() == "MOV");
                            continue;
                        }
                        if (counter == 1) {
                            REQUIRE(i.getOperation()->getOpCode() == "JMP");
                            continue;
                        }
                        if (counter == 12) {
                            REQUIRE(i.getOperation()->getOpCode() == "MOV");
                            continue;
                        }
                        if (counter == 13) {
                            REQUIRE(i.getOperation()->getOpCode() == "JMP");
                            continue;
                        }
                        if (counter == 14) {
                            REQUIRE(i.getOperation()->getOpCode() == "MOV");
                            continue;
                        }
                        if (counter == MARSConstants::MEMORY_ARRAY_SIZE - 2) {
                            REQUIRE(i.getOperation()->getOpCode() == "MOV");
                            continue;
                        }
                        if (counter == MARSConstants::MEMORY_ARRAY_SIZE - 1) {
                            REQUIRE(i.getOperation()->getOpCode() == "JMP");
                            continue;
                        }
                        if (i.getOperation()->getOpCode() != ParserConstants::INSTR_CODE_DAT) {
                            success = false;

                            REQUIRE(counter == 0);
                            break;
                        }
                    }
                    REQUIRE(success);
                }
            }
        }
    }
}