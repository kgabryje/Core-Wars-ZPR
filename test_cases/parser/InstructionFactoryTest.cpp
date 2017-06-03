#include "test_cases/catch.hpp"
#include "logic/parser/InstructionFactory.h"
#include "logic/parser/InstructionData.h"
#include "logic/mars/Instruction.h"
#include "logic/mars/DatInstruction.h"
#include "logic/parser/RedcodeParser.h"
#include "logic/parser/ParserException.h"

SCENARIO("InstructionFactoryTest: validating instruction code", "[parser]") {
    WHEN("Unknown instruction type has been provided") {
        const string code = "LOL";
        THEN("Exception with code is thrown") {
            REQUIRE_THROWS_AS(
                    InstructionFactory::createInstruction(code), ParserException
            );
            REQUIRE_THROWS_WITH(
                    InstructionFactory::createInstruction(code), ParserConstants::UKNOWN_CODE_EXCEPTION + code
            );
        }
    }
    WHEN("Correct instruction type has been provided",) {
        const string code = "MOV";
        THEN("No exceptions are thrown") {
            REQUIRE_NOTHROW(
                    InstructionFactory::createInstruction(code)
            );
        }
        AND_THEN("Instruction contains proper code") {
            shared_ptr<Instruction> instr = InstructionFactory::createInstruction(code);
            REQUIRE(
                    instr.get()->getOpCode() == code
            );
        }

    }
}

