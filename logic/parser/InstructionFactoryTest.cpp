#include "./catch.hpp"
#include "InstructionFactory.h"


TEST_CASE( "Life, the universe and everything", "[42][theAnswer]" ) {
    InstructionFactory::createInstruction(InstructionData("a", "fdsb", "cds"));
REQUIRE( 1 == 31 );
}