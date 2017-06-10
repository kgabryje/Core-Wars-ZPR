#include "test_cases/catch.hpp"
#include "logic/mars/OperationParamsInstructions.h"
#include <logic/parser/OperationFactory.h>
#include <logic/parser/InstructionCreator.h>
#include <logic/mars/ProcessActionContinue.h>
#include <logic/mars/OperationParamsMixed.h>
#include <logic/mars/ProcessActionRemove.h>

SCENARIO("DatOperationTest: checking DAT instr") {
    std::shared_ptr<MarsOperation> datOper = OperationFactory::createOperation(ParserConstants::INSTR_CODE_DAT);
    REQUIRE(datOper.get()->getOpCode() == ParserConstants::INSTR_CODE_DAT);
    GIVEN("Params: instruction and number as OperationMixedParams") {

        int num = 5;
        std::string code(ParserConstants::INSTR_CODE_MOV);
        std::string aField("#3");
        std::string bField("$8");
        Instruction instr = InstructionCreator::tryCreate(InstructionData(code, aField, bField));
        OperationParams *mixedParams = new OperationParamsMixed(num, instr);

        WHEN("MovOperation is executed") {
            OperationResult res = mixedParams->accept(datOper);

            THEN("ProcessAction has correct Type") {

                ProcessActionRemove *con = dynamic_cast<ProcessActionRemove *> (res.getPrecessAction().get());
                REQUIRE(con != nullptr);

                AND_THEN("Parameter Instruction bValue has not changed") {
                    REQUIRE(instr.getAddressB().get()->getValue() == 8);
                }
                AND_THEN("Parameter Instruction code has not changed") {
                    REQUIRE(instr.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_MOV);
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
        std::string aFieldSec("@7");
        std::string bFieldSec("#2");
        Instruction instrSec = InstructionCreator::tryCreate(InstructionData(codeSec, aFieldSec, bFieldSec));

        OperationParams *doubleInstrParams = new OperationParamsInstructions(instr, instrSec);

        REQUIRE(doubleInstrParams != nullptr);
        WHEN("MovOperation is executed") {
            OperationResult res = doubleInstrParams->accept(datOper);
            THEN("ProcessAction has correct Type") {

                ProcessActionRemove *con = dynamic_cast<ProcessActionRemove *> (res.getPrecessAction().get());
                REQUIRE(con != nullptr);

                AND_THEN("Instruction aValue and bValue did not changed") {
                    instr.addToBValue(5);
                    REQUIRE(instrSec.getAddressA().get()->getValue() == 7);
                    REQUIRE(instrSec.getAddressB().get()->getValue() == 2);
                }
                AND_THEN("Instruction code did not changed") {
                    REQUIRE(instrSec.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_MOV);
                }
            }
        }
        delete doubleInstrParams;
    }
}
