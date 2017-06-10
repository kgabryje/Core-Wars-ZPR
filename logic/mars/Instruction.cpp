#include "Instruction.h"

Instruction::Instruction(const std::shared_ptr<InstructionModifier> operatorA,
                         const std::shared_ptr<InstructionModifier> operatorB) : addressA(operatorA),
                                                                                 addressB(operatorB) {}

Instruction::Instruction(const std::shared_ptr<MarsOperation> operation) : operation(operation) {}

Instruction::Instruction(const std::shared_ptr<MarsOperation> operation,
                         const std::shared_ptr<InstructionModifier> operatorA,
                         const std::shared_ptr<InstructionModifier> operatorB) : operation(operation),
                                                                                   addressA(operatorA),
                                                                                   addressB(operatorB) {}

const std::shared_ptr<InstructionModifier> Instruction::getAddressA() const {
    return addressA;
}

void Instruction::setAddressA(const std::shared_ptr<InstructionModifier> addressA) {
    this->addressA.reset(addressA->clone());
}

const std::shared_ptr<InstructionModifier> Instruction::getAddressB() const {
    return addressB;
}

void Instruction::setAddressB(const std::shared_ptr<InstructionModifier> addressB) {
    this->addressB.reset(addressB->clone());
}

void Instruction::setOperation(const std::shared_ptr<MarsOperation> operation) {
    this->operation.reset(operation->clone());

}

const std::shared_ptr<MarsOperation> Instruction::getOperation() const {
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

void Instruction::setAValue(int i) {
    this->addressA.get()->setValue(i);
}

void Instruction::setBValue(int i) {
    this->addressB.get()->setValue(i);
}

int Instruction::getLastMemoryIndex() const {
    return lastMemoryIndex;
}

void Instruction::setLastMemoryIndex(int lastMemoryIndex) {
    Instruction::lastMemoryIndex = lastMemoryIndex;
}


