#include <logic/parser/InstructionData.h>
#include <logic/parser/InstructionCreator.h>
#include "catch.hpp"

using namespace std;

SCENARIO("InstructionCreatorTest: create Instruction from InstructionData") {
    WHEN("One address field in InstructionData is defined") {
        string code = "DAT";
        string aField = "#-6";
        string bField = "";
        InstructionData id(code, aField, bField);
        THEN("OpCode and one instruction address field has proper value") {
            shared_ptr<Instruction> instr = InstructionCreator::tryCreate(id);
            REQUIRE(
                    instr->getOpCode() == code
            );
            REQUIRE(
                    instr->getAddressA()->getModifier().getModifierCode() == "#"
            );
            REQUIRE(
                    instr->getAddressA()->getValue() == -6
            );
        }
        AND_WHEN("Two address fields are defined") {
            string bField = "@999";
            InstructionData id(code, aField, bField);
            THEN("Both are present in the created Instruction") {
                shared_ptr<Instruction> instr = InstructionCreator::tryCreate(id);
                REQUIRE(
                        instr->getOpCode() == code
                );
                REQUIRE(
                        instr->getAddressA()->getModifier().getModifierCode() == "#"
                );
                REQUIRE(
                        instr->getAddressA()->getValue() == -6
                );
                REQUIRE(
                        instr->getAddressB()->getModifier().getModifierCode() == "@"
                );
                REQUIRE(
                        instr->getAddressB()->getValue() == 999
                );
            }
        }
    }


}