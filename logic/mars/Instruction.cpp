#include "Instruction.h"

Instruction::Instruction(const boost::shared_ptr<InstructionAddress> operatorA,
                         const boost::shared_ptr<InstructionAddress> operatorB) : addressA(
        operatorA), addressB(operatorB) {}

Instruction::Instruction(const boost::shared_ptr<Operation> operation) : operation(operation) {}

Instruction::Instruction(const boost::shared_ptr<Operation> operation,
                         const boost::shared_ptr<InstructionAddress> operatorA,
                         const boost::shared_ptr<InstructionAddress> operatorB) : operation(operation), addressA(
        operatorA), addressB(operatorB) {}

const boost::shared_ptr<InstructionAddress> &Instruction::getAddressA() const {
    return addressA;
}

void Instruction::setAddressA(const boost::shared_ptr<InstructionAddress> &addressA) {
    Instruction::addressA = addressA;
}

const boost::shared_ptr<InstructionAddress> &Instruction::getAddressB() const {
    return addressB;
}

void Instruction::setAddressB(const boost::shared_ptr<InstructionAddress> &addressB) {
    Instruction::addressB = addressB;
}

void Instruction::setOperation(const boost::shared_ptr<Operation> &operation) {
    Instruction::operation = operation;
}

const boost::shared_ptr<Operation> &Instruction::getOperation() const {
    return operation;
}

