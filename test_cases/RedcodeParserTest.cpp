#include "catch.hpp"
#include <logic/parser/InstructionParser.h>
#include <iostream>
#include "logic/parser/RedcodeParser.h"

SCENARIO("RedCodeParserTest: parsing isntructions from text") {
    GIVEN("RedCodeParser and string as an user input") {
        WHEN("UserInput is correct") {
            string userInput = "MOV #0  ;comment\n"
                    ";comment\n"
                    "            DAT #-23 ,   8";
            THEN("WhiteSpaces are removaed and correct instructions are produced") {
                std::vector<std::shared_ptr<Instruction>> parsed = RedcodeParser::parse(userInput);
                shared_ptr<Instruction> instrMOV = parsed[0];
                shared_ptr<Instruction> instrDAT = parsed[1];
                REQUIRE(
                        instrMOV->getOpCode() == "MOV"
                );
                REQUIRE(
                        instrMOV->getAddressA()->getModifier().getModifierCode() == "#"
                );
                REQUIRE(
                        instrMOV->getAddressA()->getValue() == 0
                );
                REQUIRE(
                        instrDAT->getOpCode() == "DAT"
                );
                REQUIRE(
                        instrDAT->getAddressA()->getModifier().getModifierCode() == "#"
                );
                REQUIRE(
                        instrDAT->getAddressA()->getValue() == -23
                );
                REQUIRE(
                        instrDAT->getAddressB()->getModifier().getModifierCode() == "$"
                );
                REQUIRE(
                        instrDAT->getAddressB()->getValue() == 8
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