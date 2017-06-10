#include "test_cases/catch.hpp"
#include <logic/parser/InstructionParser.h>
#include "logic/parser/RedcodeParser.h"

SCENARIO("RedCodeParserTest: parsing isntructions from text") {
    GIVEN("RedCodeParser and string as an user input") {
        WHEN("UserInput is correct") {
            string userInput = "MOV #0  ;comment\n"
                    ";comment\n"
                    "            DAT #-23 ,   8";
            THEN("WhiteSpaces are removed and correct instructions are produced") {
                std::vector<Instruction> parsed = RedcodeParser::parse(userInput);
                Instruction instrMOV = parsed[0];
                Instruction instrDAT = parsed[1];
                REQUIRE(
                        instrMOV.getOperation()->getOpCode() == "MOV"
                );
                REQUIRE(
                        instrMOV.getAddressA()->getModifierCode() == "#"
                );
                REQUIRE(
                        instrMOV.getAddressA()->getValue() == 0
                );
                REQUIRE(
                        instrDAT.getOperation()->getOpCode() == "DAT"
                );
                REQUIRE(
                        instrDAT.getAddressA()->getModifierCode() == "#"
                );
                REQUIRE(
                        instrDAT.getAddressA()->getValue() == -23
                );
                REQUIRE(
                        instrDAT.getAddressB()->getModifierCode() == "$"
                );
                REQUIRE(
                        instrDAT.getAddressB()->getValue() == 8
                );
            }
        }
        WHEN("UserInput is NOT correct - wrong identifier") {
            string userInput = "MOV #0  ;comment\n"
                    "\n"
                    "            DAT  !-23 ,   8\n";
            THEN("Exception with correct line is thrown") {
                REQUIRE_THROWS_WITH(
                        RedcodeParser::parse(userInput),
                        ParserConstants::UKNOWN_MODIFIER_EXCEPTION + "\"!\" (line: 3)"
                );
            }
        }

        AND_WHEN("UserInput is NOT correct - wrong number format") {
            string userInput_wrong = "MOV #0  ;comment\n"
                    "\n"
                    ";comment sda \n"
                    "            DAT  -2a3 ,   8\n";
            THEN("Exception with correct line is thrown") {
                REQUIRE_THROWS_WITH(

                        RedcodeParser::parse(userInput_wrong),
                        ParserConstants::WRONG_SYNTAX_EXCEPTION + "(line: 4)"
                );
            }
        }

    }
}