#include "test_cases/catch.hpp"
#include <logic/parser/InstructionModifier.h>
#include <logic/parser/InstructionModifierCreator.h>
#include "logic/parser/RedcodeParser.h"

SCENARIO("AddressCreatorTest: Creating RedCode addresses from text") {
    WHEN("Address text is correct") {
        string modifier = "@";
        string value = "-125";
        string rawAddress = modifier + value;

        THEN("Produce correct InstructionModifier") {
            InstructionModifier ia = *InstructionModifierCreator::tryCreate(rawAddress);
            REQUIRE(
                    ia.getValue() == -125
            );
            REQUIRE(
                    ia.getModifierCode() == "@"
            );

        }
        AND_WHEN("No modifier given") {
            string rawAddress = value;
            THEN("Parse direct mode address") {
                InstructionModifier ia = *InstructionModifierCreator::tryCreate(rawAddress);
                REQUIRE(
                        ia.getValue() == -125
                );
                REQUIRE(
                        ia.getModifierCode() == "$"
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
                    InstructionModifierCreator::tryCreate(rawAddress),
                    ParserConstants::UKNOWN_MODIFIER_EXCEPTION + "\"" + modifier + "\" "
            );
        }
    }
    WHEN("Number has wrong format") {
        string modifier = "@";
        string value = "3a4";
        string rawAddress = modifier + value;

        THEN("fire exception with proper message") {
            REQUIRE_THROWS_WITH(
                    InstructionModifierCreator::tryCreate(rawAddress),
                    ParserConstants::WRONG_NUMBER_EXCEPTION
            );
        }
    }
}