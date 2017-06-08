#include <logic/parser/InstructionData.h>
#include <logic/parser/InstructionCreator.h>
#include "test_cases/catch.hpp"

SCENARIO("Instruction test: arithmetic operation on the B field") {
    int val = 12;
    std::string code("DAT");
    std::string aField("#3");
    std::string bField("$8");
    Instruction instr = InstructionCreator::tryCreate(InstructionData(code, aField, bField));

    WHEN("There is some number added to BField") {
        THEN("Result should be sum of old BField value and given number") {
            instr.addToBValue(val);
            REQUIRE(instr.getAddressB().get()->getValue() == 20);
        }
    }
};