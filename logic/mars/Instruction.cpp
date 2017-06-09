#include "Instruction.h"

Instruction::Instruction(const boost::shared_ptr<InstructionModifier> operatorA,
                         const boost::shared_ptr<InstructionModifier> operatorB) : addressA(
        operatorA), addressB(operatorB) {}

Instruction::Instruction(const boost::shared_ptr<MarsOperation> operation) : operation(operation) {}

Instruction::Instruction(const boost::shared_ptr<MarsOperation> operation,
                         const boost::shared_ptr<InstructionModifier> operatorA,
                         const boost::shared_ptr<InstructionModifier> operatorB) : operation(operation), addressA(
        operatorA), addressB(operatorB) {}

const boost::shared_ptr<InstructionModifier> &Instruction::getAddressA() const {
    return addressA;
}

void Instruction::setAddressA(const boost::shared_ptr<InstructionModifier> &addressA) {
    Instruction::addressA = addressA;
}

const boost::shared_ptr<InstructionModifier> &Instruction::getAddressB() const {
    return addressB;
}

void Instruction::setAddressB(const boost::shared_ptr<InstructionModifier> &addressB) {
    Instruction::addressB = addressB;
}

void Instruction::setOperation(const boost::shared_ptr<MarsOperation> &operation) {
    Instruction::operation = operation;
}

const boost::shared_ptr<MarsOperation> &Instruction::getOperation() const {
    return operation;
}

void Instruction::addToAValue(int i) {
    int old = this->addressA.get()->getValue();
    this->addressA.get()->setValue(old + i);
}


void Instruction::addToBValue(int i) {
    int old = this->addressB.get()->getValue();
    this->addressB.get()->setValue(old + i);
}

int Instruction::getAValue() {
    return this->addressA.get()->getValue();
}

int Instruction::getBValue() {
    return this->addressB.get()->getValue();
}


