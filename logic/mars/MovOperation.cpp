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
    std::cout << "TestMovOperation1" << std::endl;
    Instruction first = operParams->getFirstInstruction();
    std::cout << "operParams->getFirstInstruction()" << operParams->getFirstInstruction().getOperation()->getOpCode()
              << std::endl;
    std::cout << "operParams->getFirstInstruction() AValue" << operParams->getFirstInstruction().getAValue()
              << std::endl;
    std::cout << "operParams->getFirstInstruction() BValue" << operParams->getFirstInstruction().getBValue()
              << std::endl;
    std::cout << "operParams->getSecondtInstruction()" << operParams->getSecondInstruction().getOperation()->getOpCode()
              << std::endl;
    std::cout << "operParams->getSecondtInstruction() AValue" << operParams->getSecondInstruction().getAValue()
              << std::endl;
    std::cout << "operParams->getSecondtInstruction() BValue" << operParams->getSecondInstruction().getBValue()
              << std::endl;
    std::cout << "TestMovOperation2" << std::endl;
    Instruction second = operParams->getSecondInstruction();
    std::cout << "TestMovOperation3" << std::endl;
    second.setOperation(first.getOperation());
    std::cout << "TestMovOperation4" << std::endl;
    second.setAddressA(first.getAddressA());
    std::cout << "TestMovOperation5" << std::endl;
    second.setAddressB(first.getAddressB());
    std::cout << "TestMovOperation6" << std::endl;
    std::vector<Instruction> instructionsToModify;
    instructionsToModify.push_back(second);
    return OperationResult(std::shared_ptr<ProcessAction>(new ProcessActionContinue()), instructionsToModify);
}

MarsOperation *MovOperation::clone() const {
    return new MovOperation(*this);
}
