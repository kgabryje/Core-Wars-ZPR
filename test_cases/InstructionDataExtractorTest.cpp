#include <logic/parser/InstructionDataExtractor.h>
#include <logic/parser/ParserException.h>
#include "catch.hpp"
#include "logic/parser/RedcodeParser.h"

SCENARIO("InstructionDataExtractor: validating instructions""[parser]") {

    GIVEN("Simple InstructionDataExtractor") {
        InstructionDataExtractor extractor;

        WHEN("Instructions are syntactically correct") {
            THEN("Validation return true") {
                REQUIRE(
                        extractor.isInstructionValid("RAZ #0") == true
                );
                REQUIRE(
                        extractor.isInstructionValid("DWA #0, #8") == true
                );
                REQUIRE(
                        extractor.isInstructionValid("DWA <0, ]8") == true
                );
                REQUIRE(
                        extractor.isInstructionValid("TRZ    #0") == true
                );
                REQUIRE(
                        extractor.isInstructionValid("ABC -8,-8") == true
                );
                REQUIRE(
                        extractor.isInstructionValid("  JMP -2           ; next instruction") == true
                );
                REQUIRE(
                        extractor.isInstructionValid("  DAT #0,    #4        ; next instruction") == true
                );
            }
        }
        AND_WHEN("Instructions are NOT syntactically correct") {
            THEN("Validation return false") {
                REQUIRE(
                        extractor.isInstructionValid("some random text") != true
                );
                REQUIRE(
                        extractor.isInstructionValid("ABC 6,") != true
                );
                REQUIRE(
                        extractor.isInstructionValid("DEF ##6") != true
                );
            }
        }

    }
}

SCENARIO("InstructionDataExtractor: extracting instruction components""[parser]") {
    GIVEN("Simple InstructionDataExtractor and instruction as string") {
        InstructionDataExtractor extractor;
        std::string opCode = "AAA";
        std::string aField = "^3";
        std::string bField = "$-9";
        std::string space = " ";
        std::string empty = "";

        WHEN("Raw instruction text has Op-code and one address") {
            std::string rawInstr = opCode + space + aField;

            THEN("Instruction with one only one address filled is return") {
                InstructionData metaInstr = extractor.tryExtract(rawInstr);

                REQUIRE(
                        metaInstr.getCode() == opCode
                );
                REQUIRE(
                        metaInstr.getA_field() == aField
                );
                REQUIRE(
                        metaInstr.getB_field() == empty
                );
            }

        }
        WHEN("Raw instruction text has Op-code and two addresses") {
            std::string rawInstr = opCode + space + aField + "," + bField;

            THEN("Instruction with one only one address filled is return") {
                InstructionData metaInstr = extractor.tryExtract(rawInstr);

                REQUIRE(
                        metaInstr.getCode() == opCode
                );
                REQUIRE(
                        metaInstr.getA_field() == aField
                );
                REQUIRE(
                        metaInstr.getB_field() == bField
                );
            }
        }
        WHEN("wrong instr syntax") {
            std::string rawInstr = opCode;

            THEN("fire exception") {

                REQUIRE_THROWS_AS(
                        extractor.tryExtract(rawInstr), ParserException
                );
            }
        }
    }
}

