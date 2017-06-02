#include <logic/parser/InstructionDataExtractor.h>
#include <logic/parser/InstructionAddress.h>
#include <logic/parser/AddressCreator.h>
#include "catch.hpp"
#include "logic/parser/RedcodeParser.h"

SCENARIO("AddressCreatorTest: Creating RedCode addresses from text") {
    WHEN("Address text is correct") {
        string modifier = "@";
        string value = "-125";
        string rawAddress = modifier + value;

        THEN("Produce correct InstructionAddress") {
            InstructionAddress ia = AddressCreator::tryCreate(rawAddress);
            REQUIRE(
                    ia.getValue() == -125
            );
            InstructionModifier im = ia.getModifier();
            REQUIRE(
                    im.getModifierCode() == "@"
            );

        }
        AND_WHEN("No modifier given") {
            string rawAddress = value;
            THEN("Parse direct mode address") {
                InstructionAddress ia = AddressCreator::tryCreate(rawAddress);
                REQUIRE(
                        ia.getValue() == -125
                );
                InstructionModifier im = ia.getModifier();
                REQUIRE(
                        im.getModifierCode() == "$"
                );
            }
        }
        AND_WHEN("Instruction string is empty") {
            THEN("throw ex") {
                REQUIRE_THROWS(AddressCreator::tryCreate(rawAddress)
                );

            }
        }
    }
    WHEN("Address modifier is unknown") {
        string modifier = "~";
        string value = "34";
        string rawAddress = modifier + value;

        THEN("fire exception with proper message") {
            REQUIRE_THROWS_WITH(
                    AddressCreator::tryCreate(rawAddress),
                    ParserConstants::UKNOWN_MODIFIER_EXCEPTION
            );
        }
    }
    WHEN("Number has wrong format") {
        string modifier = "@";
        string value = "3a4";
        string rawAddress = modifier + value;

        THEN("fire exception with proper message") {
            REQUIRE_THROWS_WITH(
                    AddressCreator::tryCreate(rawAddress),
                    ParserConstants::WRONG_NUMBER_EXCEPTION
            );
        }
    }
}