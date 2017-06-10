#include <logic/mars/MarsEngine.h>
#include "test_cases/catch.hpp"

class MarsEngine;

MarsEngine *prepareMars();

boost::shared_ptr<InstructionModifier> prepareInstrMod(std::string value);

SCENARIO("Immediate modifier test: returning empty optionals") {
    GIVEN("MarsEngine with added instructions and MemoryIndex") {
        MarsEngine *mars = prepareMars();
        MemoryIndex indexOne(8);
        WHEN("Immediate modifier points to empty memory (DAT default)") {
            boost::shared_ptr<InstructionModifier> minus2 = prepareInstrMod("#-3");
            THEN("Fetched optional is empty") {
                boost::optional<Instruction> i = minus2->findTargetInstruction(indexOne, mars->getMemoryArray());
                REQUIRE(i.is_initialized() == false);

            }
        }
        AND_WHEN("Immediate modifier points to inserted instruction") {
            boost::shared_ptr<InstructionModifier> plus2 = prepareInstrMod("#3");
            THEN("Fetched optional is empty") {
                boost::optional<Instruction> i = plus2->findTargetInstruction(indexOne, mars->getMemoryArray());
                REQUIRE(i.is_initialized() == false);
            }
        }
    }
}

