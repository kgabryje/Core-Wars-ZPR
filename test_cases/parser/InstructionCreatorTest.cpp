#include "test_cases/catch.hpp"

#include <logic/parser/InstructionData.h>
#include <logic/parser/InstructionCreator.h>

using namespace std;

SCENARIO("InstructionCreatorTest: create Instruction from InstructionData") {
    WHEN("One address field in InstructionData is defined") {
        string code = "DAT";
        string aField = "#-6";
        string bField = "";
        InstructionData id(code, aField, bField);
        THEN("OpCode and one instruction address field has proper value and second has default") {
            Instruction instr = InstructionCreator::tryCreate(id);
            REQUIRE(
                    instr.getOperation()->getOpCode() == code
            );
            REQUIRE(
                    instr.getAddressA()->getModifier().getModifierCode() == "#"
            );
            REQUIRE(
                    instr.getAddressA()->getValue() == -6
            );
            REQUIRE(
                    instr.getAddressB()->getModifier().getModifierCode() == "$"
            );
            REQUIRE(
                    instr.getAddressB()->getValue() == 0
            );
        }
        AND_WHEN("Two address fields are defined") {
            string bField = "@999";
            InstructionData id(code, aField, bField);
            THEN("Both are present in the created Instruction") {
                Instruction instr = InstructionCreator::tryCreate(id);
                REQUIRE(
                        instr.getOperation()->getOpCode() == code
                );
                REQUIRE(
                        instr.getAddressA()->getModifier().getModifierCode() == "#"
                );
                REQUIRE(
                        instr.getAddressA()->getValue() == -6
                );
                REQUIRE(
                        instr.getAddressB()->getModifier().getModifierCode() == "@"
                );
                REQUIRE(
                        instr.getAddressB()->getValue() == 999
                );
            }
        }
    }

}