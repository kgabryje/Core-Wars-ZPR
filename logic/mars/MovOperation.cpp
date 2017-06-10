#include "MovOperation.h"
#include "ProcessActionContinue.h"

MovOperation::MovOperation() : MarsOperation(ParserConstants::INSTR_CODE_MOV) {

}

std::shared_ptr<ProcessAction> MovOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    Instruction &i = operParams->getInstruction();
    i.setBValue(num);
    return std::shared_ptr<ProcessAction>(new ProcessActionContinue());
}

std::shared_ptr<ProcessAction> MovOperation::runOperation(OperationParamsInstructions *operParams) {

    Instruction &first = operParams->getFirstInstruction();
    Instruction &second = operParams->getSecondInstruction();
    second.setOperation(first.getOperation());
    second.setAddressA(first.getAddressA().get()->clone());
    second.setAddressB(first.getAddressB().get()->clone());

    return std::shared_ptr<ProcessAction>(new ProcessActionContinue());
}
