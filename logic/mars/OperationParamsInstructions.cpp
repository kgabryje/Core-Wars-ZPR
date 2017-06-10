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
    return operation.get()->runOperation(this);
}
