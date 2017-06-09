#include "JmpOperation.h"
#include "ProcessActionJump.h"

JmpOperation::JmpOperation() : MarsOperation(ParserConstants::INSTR_CODE_JMP) {

}

boost::shared_ptr<ProcessAction> JmpOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    return boost::shared_ptr<ProcessAction>(new ProcessActionJump(num));
}

boost::shared_ptr<ProcessAction> JmpOperation::runOperation(OperationParamsInstructions *operParams) {

    int num = operParams->getFirstInstruction().getAValue();
    return boost::shared_ptr<ProcessAction>(new ProcessActionJump(num));
}
