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
        WHEN("Warrior code is inserted") {
            int beginningAddress = 12;
            std::string userInput = "MOV #0 \n"
                    "JMP $5, @2\n"
                    "MOV #-23,8";
            std::vector<Instruction> parsed = RedcodeParser::parse(userInput);
            mars.enterWarrior(beginningAddress, parsed);
            THEN("From beginning address starts warrior and rest is as it was before insert") {
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
        }
    }
}