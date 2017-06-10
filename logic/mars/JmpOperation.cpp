#include "JmpOperation.h"
#include "ProcessActionJump.h"

JmpOperation::JmpOperation() : MarsOperation(ParserConstants::INSTR_CODE_JMP) {

}

std::shared_ptr<ProcessAction> JmpOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    return std::shared_ptr<ProcessAction>(new ProcessActionJump(num));
}

std::shared_ptr<ProcessAction> JmpOperation::runOperation(OperationParamsInstructions *operParams) {

    int num = operParams->getFirstInstruction().getAValue();
    return std::shared_ptr<ProcessAction>(new ProcessActionJump(num));
}
