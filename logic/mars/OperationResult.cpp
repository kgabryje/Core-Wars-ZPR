#include "OperationResult.h"

OperationResult::OperationResult(const std::shared_ptr<ProcessAction> &precessAction,
                                 const std::vector<Instruction> &instructions) : processAction(precessAction),
                                                                                 instructions(instructions) {}

const std::shared_ptr<ProcessAction> &OperationResult::getPrecessAction() const {
    return processAction;
}

void OperationResult::setPrecessAction(const std::shared_ptr<ProcessAction> &precessAction) {
    OperationResult::processAction = precessAction;
}

const std::vector<Instruction> &OperationResult::getInstructions() const {
    return instructions;
}

void OperationResult::setInstructions(const std::vector<Instruction> &instructions) {
    OperationResult::instructions = instructions;
}

OperationResult::OperationResult(std::shared_ptr<ProcessAction> pAction) : processAction(pAction) {

}
