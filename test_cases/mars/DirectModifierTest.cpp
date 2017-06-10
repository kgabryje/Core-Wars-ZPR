#include <logic/mars/MarsEngine.h>
#include <logic/parser/RedcodeParser.h>
#include <logic/parser/InstructionModifierCreator.h>

#include "test_cases/catch.hpp"

MarsEngine *prepareMars();

std::shared_ptr<InstructionModifier> prepareInstrMod(string value);


SCENARIO("DirectModifierTest: fetching Instructions") {
    GIVEN("MarsEngine with added instructions and MemoryIndex") {
        MarsEngine *mars = prepareMars();
        MemoryIndex indexOne(8);

        WHEN("Direct modifier points to empty memory (DAT default)") {
            std::shared_ptr<InstructionModifier> minus2 = prepareInstrMod("-3");
            THEN("Fetched instruction has DAT operation and 2 zeros") {
                boost::optional<Instruction> i = minus2->findTargetInstruction(indexOne, mars->getMemoryArray());
                REQUIRE(i->getOperation()->getOpCode() == ParserConstants::INSTR_CODE_DAT);
                REQUIRE(i->getBValue() == 0);
                REQUIRE(i->getAValue() == 0);
            }
        }
        AND_WHEN("Direct modifier points to inserted instruction") {
            std::shared_ptr<InstructionModifier> plus2 = prepareInstrMod("3");
            THEN("That particular instruction is fetched") {
                boost::optional<Instruction> i = plus2->findTargetInstruction(indexOne, mars->getMemoryArray());
                REQUIRE(i->getOperation()->getOpCode() == ParserConstants::INSTR_CODE_JMP);
                REQUIRE(i->getBValue() == 2);
                REQUIRE(i->getAValue() == 5);
            }
        }
        delete mars;
    }
}

MarsEngine *prepareMars() {
    int beginningAddress = 10;
    MarsEngine *mars = new MarsEngine();
    string userInput =
            "MOV #0 \n"
                    "JMP $5, @2\n"
                    "MOV #-2,8\n"
                    "JMP #-23,8";
    vector<Instruction> parsed = RedcodeParser::parse(userInput);

    mars->enterWarrior(beginningAddress, parsed);
    return mars;
}

std::shared_ptr<InstructionModifier> prepareInstrMod(string value) {
    string rawAddress = value;
    return InstructionModifierCreator::tryCreate(rawAddress);

}