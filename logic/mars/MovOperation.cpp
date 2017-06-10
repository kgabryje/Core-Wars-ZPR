#include <iostream>
#include "MovOperation.h"
#include "ProcessActionContinue.h"
#include "OperationResult.h"

MovOperation::MovOperation() : MarsOperation(ParserConstants::INSTR_CODE_MOV) {

}

OperationResult MovOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    Instruction i = operParams->getInstruction();
    i.setBValue(num);
    return OperationResult(std::shared_ptr<ProcessAction>(new ProcessActionContinue()));
}

OperationResult MovOperation::runOperation(OperationParamsInstructions *operParams) {
    Instruction first = operParams->getFirstInstruction();
    Instruction second = operParams->getSecondInstruction();
    second.setOperation(first.getOperation());
    second.setAddressA(first.getAddressA());
    second.setAddressB(first.getAddressB());
    std::vector<Instruction> instructionsToModify;
    instructionsToModify.push_back(second);
    return OperationResult(std::shared_ptr<ProcessAction>(new ProcessActionContinue()), instructionsToModify);
}

MarsOperation *MovOperation::clone() const {
    return new MovOperation(*this);
}
