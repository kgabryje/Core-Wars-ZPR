#include "OperationParamsInstructions.h"

OperationParamsInstructions::OperationParamsInstructions(Instruction &instructionFirst, Instruction &instructionSecond)
        : firstInstruction(instructionFirst), secondInstruction(instructionSecond) {


}

Instruction & OperationParamsInstructions::getFirstInstruction() const {
    return firstInstruction;
}

Instruction & OperationParamsInstructions::getSecondInstruction() const {
    return secondInstruction;
}

boost::shared_ptr<ProcessAction> OperationParamsInstructions::accept(boost::shared_ptr<MarsOperation> operation) {
    return operation.get()->runOperation(this);
}
