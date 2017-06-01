#include <logic/parser/InstructionDataExtractor.h>
#include "catch.hpp"
#include "logic/parser/RedcodeParser.h"

TEST_CASE("Extractor validate properly correct instructions" "[parser]") {
    InstructionDataExtractor extractor;

    REQUIRE(
            extractor.isInstructionValid("RAZ #0") == true
    );
    REQUIRE(
            extractor.isInstructionValid("DWA #0, #8") == true
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
};

TEST_CASE("Extractor validate properly incorrect instructions" "[parser]") {
    InstructionDataExtractor extractor;
    REQUIRE(
            extractor.isInstructionValid("some random text") != true
    );
    REQUIRE(
            extractor.isInstructionValid("ABC -6,") != true
    );
    REQUIRE(
            extractor.isInstructionValid("DEF ##6") != true
    );


};