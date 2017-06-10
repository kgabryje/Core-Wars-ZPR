#include "test_cases/catch.hpp"
#include "logic/mars/OperationParamsInstructions.h"
#include <logic/parser/OperationFactory.h>
#include <logic/parser/InstructionCreator.h>
#include <logic/mars/ProcessActionContinue.h>
#include <logic/mars/OperationParamsMixed.h>

SCENARIO("AddOperationTest: checking add instr") {
    std::shared_ptr<MarsOperation> addOper = OperationFactory::createOperation(ParserConstants::INSTR_CODE_ADD);
    REQUIRE(addOper.get()->getOpCode() == ParserConstants::INSTR_CODE_ADD);
    GIVEN("Params: instruction and number as OperationMixedParams") {

        int num = 5;
        std::string code(ParserConstants::INSTR_CODE_DAT);
        std::string aField("#3");
        std::string bField("$8");
        Instruction instr = InstructionCreator::tryCreate(InstructionData(code, aField, bField));
        OperationParams *mixedParams = new OperationParamsMixed(num, instr);
        REQUIRE(instr.getAddressB().get()->getValue() == 8);

        WHEN("AddOperation is executed") {

            OperationResult res = mixedParams->accept(addOper);

            THEN("ProcessAction has correct Type") {

                ProcessActionContinue *con = dynamic_cast<ProcessActionContinue *> (res.getPrecessAction().get());
                REQUIRE(con != nullptr);

                AND_THEN("Instruction bValue is correct") {
                    REQUIRE(instr.getAddressB().get()->getValue() == 13);
                }
                AND_THEN("Instruction code is correct") {
                    REQUIRE(instr.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_DAT);
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
            OperationResult res = doubleInstrParams->accept(addOper);
            THEN("ProcessAction has correct Type") {

                ProcessActionContinue *con = dynamic_cast<ProcessActionContinue *> (res.getPrecessAction().get());
                REQUIRE(con != nullptr);

                AND_THEN("Instruction aValue and bValue are the same as in source instruction (copy)") {
                    instr.addToBValue(5);
                    REQUIRE(instrSec.getAddressA().get()->getValue() == 9);
                    REQUIRE(instrSec.getAddressB().get()->getValue() == 10);
                }
                AND_THEN("Instruction code is correct") {
                    REQUIRE(instrSec.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_MOV);
                }
            }
        }
        delete doubleInstrParams;
    }
}
