#include "JmpOperation.h"
#include "ProcessActionJump.h"
#include "OperationResult.h"

JmpOperation::JmpOperation() : MarsOperation(ParserConstants::INSTR_CODE_JMP) {

}

OperationResult JmpOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    return std::shared_ptr<ProcessAction>(new ProcessActionJump(num));
}

OperationResult JmpOperation::runOperation(OperationParamsInstructions *operParams) {

    int num = operParams->getFirstInstruction().getAValue();
    return std::shared_ptr<ProcessAction>(new ProcessActionJump(num));
}

MarsOperation *JmpOperation::clone() const {
    return new JmpOperation(*this);
}
