#include "test_cases/catch.hpp"
#include "logic/mars/OperationParamsInstructions.h"
#include <logic/parser/OperationFactory.h>
#include <logic/parser/InstructionCreator.h>
#include <logic/mars/ProcessActionContinue.h>
#include <logic/mars/OperationParamsMixed.h>
#include <logic/mars/ProcessActionJump.h>

SCENARIO("JumpOperationTest: checking jump instr") {
    std::shared_ptr<MarsOperation> addOper = OperationFactory::createOperation(ParserConstants::INSTR_CODE_JMP);
    REQUIRE(addOper.get()->getOpCode() == ParserConstants::INSTR_CODE_JMP);
    GIVEN("Params: instruction and number as OperationMixedParams") {

        int num = 5;
        std::string code(ParserConstants::INSTR_CODE_DAT);
        std::string aField("#-4");
        std::string bField("$8");
        Instruction instr = InstructionCreator::tryCreate(InstructionData(code, aField, bField));
        OperationParams *mixedParams = new OperationParamsMixed(num, instr);

        WHEN("AddOperation is executed") {

            std::shared_ptr<ProcessAction> res = mixedParams->accept(addOper);

            THEN("ProcessAction has correct Type") {

                ProcessActionJump *con = dynamic_cast<ProcessActionJump *> (res.get());
                REQUIRE(con != nullptr);

                AND_THEN("Jump value is correct") {
                    REQUIRE(con->getJumpValue() == 5);
                }

            }
        }
        delete mixedParams;
    }
    GIVEN("Params: two instructions ") {

        std::string code(ParserConstants::INSTR_CODE_DAT);
        std::string aField("#3");
        std::string bField("$8");
        Instruction instr = InstructionCreator::tryCreate(InstructionData(code, aField, bField));

        std::string codeSec(ParserConstants::INSTR_CODE_MOV);
        std::string aFieldSec("@6");
        std::string bFieldSec("#2");
        Instruction instrSec = InstructionCreator::tryCreate(InstructionData(codeSec, aFieldSec, bFieldSec));

        OperationParams *doubleInstrParams = new OperationParamsInstructions(instr, instrSec);

        REQUIRE(doubleInstrParams != nullptr);
        WHEN("MovOperation is executed") {
            std::shared_ptr<ProcessAction> res = doubleInstrParams->accept(addOper);
            THEN("ProcessAction has correct Type") {

                ProcessActionJump *con = dynamic_cast<ProcessActionJump *> (res.get());
                REQUIRE(con != nullptr);

                AND_THEN("Jump value is correct") {
                    REQUIRE(con->getJumpValue() == 3);
                }
                AND_THEN("Operation instructions did not change") {
                    REQUIRE(instr.getOperation().get()->getOpCode() == ParserConstants::INSTR_CODE_DAT);
                    REQUIRE(instr.getAValue() == 3);
                    REQUIRE(instr.getBValue() == 8);
                    REQUIRE(instrSec.getOperation().get()->getOpCode() == ParserConstants::INSTR_CODE_MOV);
                    REQUIRE(instrSec.getAValue() == 6);
                    REQUIRE(instrSec.getBValue() == 2);
                }
            }
        }
        delete doubleInstrParams;
    }
}
