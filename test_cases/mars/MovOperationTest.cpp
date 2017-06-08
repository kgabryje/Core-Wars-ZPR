#include "test_cases/catch.hpp"
#include <logic/parser/InstructionParser.h>
#include <logic/parser/OperationFactory.h>
#include <logic/parser/InstructionCreator.h>
#include <logic/mars/ProcessActionContinue.h>
#include <logic/mars/OperationParamsMixed.h>

SCENARIO("MovOperationTest: checking mov instr") {
    boost::shared_ptr<MarsOperation> movOper = OperationFactory::createOperation("MOV");
    REQUIRE(movOper.get()->getOpCode() == "MOV");
    GIVEN("Params: instruction and number as OperationMixedParams") {

        int num = 5;
        std::string code("DAT");
        std::string aField("#3");
        std::string bField("$8");
        Instruction instr = InstructionCreator::tryCreate(InstructionData(code, aField, bField));
        OperationParams *mixedParams = new OperationParamsMixed(num, instr);

        WHEN("MarsOperation is executed") {
            boost::shared_ptr<ProcessAction> res = mixedParams->accept(movOper);

            THEN("ProcessAction has correct Type") {

                ProcessActionContinue *con = dynamic_cast<ProcessActionContinue *> (res.get());
                REQUIRE(con != nullptr);

                AND_THEN("Instruction bValue is correct") {
                    REQUIRE(instr.getAddressB().get()->getValue() == 8 + 5);
                }
            }
        }
        delete mixedParams;
    }
}
