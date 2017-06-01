#include <logic/parser/InstructionDataExtractor.h>
#include <logic/parser/InstructionParser.h>
#include "catch.hpp"
#include "logic/parser/RedcodeParser.h"

SCENARIO("Checking RedCode instructions parser" "[parser]") {

    GIVEN("Simple InstructionDataExtractor") {
        InstructionParser parser;
        vector<std::string> rawInstructions;
        WHEN("Parsed instruction is correct") {
            THEN("No exceptions are thrown") {

                rawInstructions.push_back("RAZ #0");
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back("DWA #0, #8");
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back("TRZ    #0");
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back("ABC -8,-8");
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back("  JMP -2           ; next instruction");
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back("  DAT #0,    #4        ; next instruction");
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
            }
        }
        WHEN("Parsed instructions are NOT correct") {
            THEN("ParserException is thrown") {

                rawInstructions.push_back("NOT VALID INSTR");
                REQUIRE_THROWS(
                        parser.parseInstructions(rawInstructions)
                );

            }

        }

    }
}