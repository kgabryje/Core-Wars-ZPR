#include <logic/mars/MarsEngine.h>
#include "test_cases/catch.hpp"

class MarsEngine;

MarsEngine *prepareMars();

boost::shared_ptr<InstructionModifier> prepareInstrMod(std::string value);

SCENARIO("IndirectModifierTest: fetching Instructions") {
    GIVEN("MarsEngine with added instructions and MemoryIndex") {
        MarsEngine *mars = prepareMars();
        MemoryIndex indexOne(8);
        WHEN("Indirect modifier points to empty memory (DAT default)") {
            boost::shared_ptr<InstructionModifier> minus2 = prepareInstrMod("@-3");
            THEN("Fetched instruction has DAT operation and 2 zeros") {
                boost::optional<Instruction> i = minus2->findTargetInstruction(indexOne, mars->getMemoryArray());
                REQUIRE(i->getOperation()->getOpCode() == ParserConstants::INSTR_CODE_DAT);
                REQUIRE(i->getBValue() == 0);
                REQUIRE(i->getAValue() == 0);
            }
        }
        AND_WHEN("Indirect modifier points to inserted instruction") {
            boost::shared_ptr<InstructionModifier> plus2 = prepareInstrMod("@3");
            THEN("Instruction pointed by b-field of that particular instruction is fetched") {
                boost::optional<Instruction> i = plus2->findTargetInstruction(indexOne, mars->getMemoryArray());
                REQUIRE(i->getOperation()->getOpCode() == ParserConstants::INSTR_CODE_JMP);
                REQUIRE(i->getBValue() == 8);
                REQUIRE(i->getAValue() == -23);
            }
        }
    }
}

