#include <iostream>
#include "OperationParamsInstructions.h"

OperationParamsInstructions::OperationParamsInstructions(Instruction &instructionFirst, Instruction &instructionSecond)
        : firstInstruction(instructionFirst), secondInstruction(instructionSecond) {


}

Instruction OperationParamsInstructions::getFirstInstruction() const {
    return firstInstruction;
}

Instruction OperationParamsInstructions::getSecondInstruction() const {
    return secondInstruction;
}

OperationResult OperationParamsInstructions::accept(std::shared_ptr<MarsOperation> operation) {
    std::cout << "Test OperationParamsInstructions" << std::endl;
    std::cout << "std::shared_ptr<MarsOperation> operation code" << operation->getOpCode() << std::endl;
    std::cout << "Test OperationParamsInstructions this: first instr"
              << this->getFirstInstruction().getOperation()->getOpCode() << std::endl;
    std::cout << "Test OperationParamsInstructions this: first instr a val" << this->getFirstInstruction().getAValue()
              << std::endl;
    std::cout << "Test OperationParamsInstructions this: first instr b val" << this->getFirstInstruction().getBValue()
              << std::endl;
    std::cout << "Test OperationParamsInstructions this: second instr"
              << this->getSecondInstruction().getOperation()->getOpCode() << std::endl;
    std::cout << "Test OperationParamsInstructions this: second instr a val" << this->getFirstInstruction().getAValue()
              << std::endl;
    std::cout << "Test OperationParamsInstructions this: second instr a val" << this->getFirstInstruction().getBValue()
              << std::endl;
    return operation.get()->runOperation(this);
}
