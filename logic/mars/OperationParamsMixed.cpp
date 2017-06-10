#include "OperationParamsMixed.h"

OperationParamsMixed::OperationParamsMixed(int i, Instruction instruction)
        : instruction(instruction), value(i) {
}

int OperationParamsMixed::getValue() const {
    return value;
}


Instruction OperationParamsMixed::getInstruction() const {
    return instruction;
}

OperationResult OperationParamsMixed::accept(std::shared_ptr<MarsOperation> operation) {
    return operation.get()->runOperation(this);
}
