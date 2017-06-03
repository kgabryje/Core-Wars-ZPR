#include "test_cases/catch.hpp"
#include <logic/parser/InstructionDataExtractor.h>
#include <logic/parser/InstructionParser.h>


SCENARIO("Checking RedCode Instructions parser" "[parser]") {

    GIVEN("Simple InstructionDataExtractor") {
        InstructionParser parser;
        vector<std::pair<int, std::string>> rawInstructions;
        int i = 1;
        WHEN("Parsed instruction is correct") {
            THEN("No exceptions are thrown") {

                rawInstructions.push_back(std::pair<int, std::string>(i, "MOV #0"));
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back(std::pair<int, std::string>(i, "MOV #0, #8"));
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back(std::pair<int, std::string>(i, "MOV    #0"));
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back(std::pair<int, std::string>(i, "MOV -8,-8"));
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back(std::pair<int, std::string>(i, "  MOV #0,    #4        ; next instruction"));
                REQUIRE_NOTHROW (
                        parser.parseInstructions(rawInstructions)
                );
                rawInstructions.push_back(std::pair<int, std::string>(i, "  MOV -2           ; next instruction"));
                REQUIRE_NOTHROW(
                        parser.parseInstructions(rawInstructions)
                );
            }
        }
        WHEN("Some of parsed instructions are NOT correct semantically") {
            rawInstructions.push_back(std::pair<int, std::string>(i, "MOV #0"));
            rawInstructions.push_back(std::pair<int, std::string>(i, "NOT VALID INSTR"));
            THEN("ParserException is thrown") {
                REQUIRE_THROWS(
                        parser.parseInstructions(rawInstructions)
                );

            }

        }

    }
}