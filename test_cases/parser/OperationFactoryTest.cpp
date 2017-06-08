#include "test_cases/catch.hpp"
#include "logic/parser/OperationFactory.h"
#include "logic/parser/InstructionData.h"
#include "logic/mars/Operation.h"
#include "logic/mars/MovOperation.h"
#include "logic/mars/DatOperation.h"
#include "logic/parser/RedcodeParser.h"
#include "logic/parser/ParserException.h"

SCENARIO("OperationFactoryTest: validating operation code", "[parser]") {
    WHEN("Unknown instruction type has been provided") {
        const string code = "LOL";
        THEN("Exception with code is thrown") {
            REQUIRE_THROWS_AS(
                    OperationFactory::createOperation(code), ParserException
            );
            REQUIRE_THROWS_WITH(
                    OperationFactory::createOperation(code), ParserConstants::UKNOWN_CODE_EXCEPTION + code
            );
        }
    }
    WHEN("Correct instruction type has been provided") {
        const string code = "MOV";
        THEN("No exceptions are thrown") {
            REQUIRE_NOTHROW(
                    OperationFactory::createOperation(code)
            );
        }
        AND_THEN("Instruction contains proper code") {
            boost::shared_ptr<Operation> oper = OperationFactory::createOperation(code);
            REQUIRE(
                    oper.get()->getOpCode() == code
            );
        }

    }
}

