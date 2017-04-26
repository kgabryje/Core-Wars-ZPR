#include "./catch_config.hpp"
#include "../logic/parser/InstructionFactory.h"


TEST_CASE( "Life, the universe and everything", "[42][theAnswer]" ) {
    InstructionFactory::createInstruction(InstructionData("a", "fdsb", "cds"));
    REQUIRE( 1 == 31 );
}
