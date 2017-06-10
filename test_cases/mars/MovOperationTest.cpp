#include "test_cases/catch.hpp"
#include "logic/mars/OperationParamsInstructions.h"
#include <logic/parser/OperationFactory.h>
#include <logic/parser/InstructionCreator.h>
#include <logic/mars/ProcessActionContinue.h>
#include <logic/mars/OperationParamsMixed.h>

SCENARIO("MovOperationTest: checking mov instr") {
    std::shared_ptr<MarsOperation> movOper = OperationFactory::createOperation("MOV");
    REQUIRE(movOper.get()->getOpCode() == "MOV");
    GIVEN("Params: instruction and number as OperationMixedParams") {

        int num = 5;
        std::string code("DAT");
        std::string aField("#3");
        std::string bField("$8");
        Instruction instr = InstructionCreator::tryCreate(InstructionData(code, aField, bField));
        OperationParams *mixedParams = new OperationParamsMixed(num, instr);

        WHEN("MovOperation is executed") {
            REQUIRE(instr.getAddressB().get()->getValue() == 8);
            std::shared_ptr<ProcessAction> res = mixedParams->accept(movOper);
            THEN("ProcessAction has correct Type") {

                ProcessActionContinue *con = dynamic_cast<ProcessActionContinue *> (res.get());
                REQUIRE(con != nullptr);

                AND_THEN("Instruction bValue is correct") {
                    REQUIRE(instr.getAddressB().get()->getValue() == 5);
                }
                AND_THEN("Instruction code is correct") {
                    REQUIRE(instr.getOperation()->getOpCode() == "DAT");
                }
            }
        }
        delete mixedParams;
    }
    GIVEN("Params: two instructions ") {

        std::string code("DAT");
        std::string aField("#3");
        std::string bField("$8");
        Instruction instr = InstructionCreator::tryCreate(InstructionData(code, aField, bField));

        std::string codeSec("MOV");
        std::string aFieldSec("@7");
        std::string bFieldSec("#2");
        Instruction instrSec = InstructionCreator::tryCreate(InstructionData(codeSec, aFieldSec, bFieldSec));

        OperationParams *doubleInstrParams = new OperationParamsInstructions(instr, instrSec);

        REQUIRE(doubleInstrParams != nullptr);
        WHEN("MovOperation is executed") {
            std::shared_ptr<ProcessAction> res = doubleInstrParams->accept(movOper);
            THEN("ProcessAction has correct Type") {

                ProcessActionContinue *con = dynamic_cast<ProcessActionContinue *> (res.get());
                REQUIRE(con != nullptr);

                AND_THEN("Instruction aValue and bValue are the same as in source instruction (copy)") {
                    instr.addToBValue(5);
                    REQUIRE(instrSec.getAddressA().get()->getValue() == 3);
                    REQUIRE(instrSec.getAddressB().get()->getValue() == 8);
                }
                AND_THEN("Instruction code is correct") {
                    REQUIRE(instrSec.getOperation()->getOpCode() == "DAT");
                }
            }
        }
        delete doubleInstrParams;
    }
}
