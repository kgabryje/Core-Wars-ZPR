#include "Instruction.h"


/**
 * Constructor without specified operation
 * @param operatorA first address
 * @param operatorB second address
 */
Instruction::Instruction(const std::shared_ptr<InstructionModifier> operatorA,
                         const std::shared_ptr<InstructionModifier> operatorB) : addressA(operatorA),
                                                                                 addressB(operatorB) {}

/**
 * Constructor without specified operators
 * @param operation Operation
 */
Instruction::Instruction(const std::shared_ptr<MarsOperation> operation) : operation(operation) {}

/**
 * Constructor
 * @param operation Operation
 * @param operatorA First address
 * @param operatorB Second address
 */
Instruction::Instruction(const std::shared_ptr<MarsOperation> operation,
                         const std::shared_ptr<InstructionModifier> operatorA,
                         const std::shared_ptr<InstructionModifier> operatorB) : operation(operation),
                                                                                   addressA(operatorA),
                                                                                   addressB(operatorB) {}

/**
 * Returns first address
 * @return addressA
 */
const std::shared_ptr<InstructionModifier> Instruction::getAddressA() const {
    return addressA;
}

/**
 * Sets first address
 * @param addressA First address
 */
void Instruction::setAddressA(const std::shared_ptr<InstructionModifier> addressA) {
    this->addressA.reset(addressA->clone());
}

/**
 * Returns second address
 * @return addressB
 */
const std::shared_ptr<InstructionModifier> Instruction::getAddressB() const {
    return addressB;
}

/**
 * Sets second address
 * @param addressA Second address
 */
void Instruction::setAddressB(const std::shared_ptr<InstructionModifier> addressB) {
    this->addressB.reset(addressB->clone());
}


/**
 * Sets operation
 * @param operation
 */
void Instruction::setOperation(const std::shared_ptr<MarsOperation> operation) {
    this->operation.reset(operation->clone());

}

/**
 * Returns operation
 * @return operation
 */
const std::shared_ptr<MarsOperation> Instruction::getOperation() const {
    return operation;
}

/**
 * Adds i to addressA
 * @param i value to add
 */
void Instruction::addToAValue(int i) {
    int old = this->addressA.get()->getValue();
    this->addressA.get()->setValue(old + i);
}

/**
 * Adds i to addressB
 * @param i value to add
 */
void Instruction::addToBValue(int i) {
    int old = this->addressB.get()->getValue();
    this->addressB.get()->setValue(old + i);
}


/**
 * Returns value of first address
 * @return value of first address
 */
int Instruction::getAValue() {
    return this->addressA.get()->getValue();
}

/**
 * Returns value of second address
 * @return value of second address
 */
int Instruction::getBValue() {
    return this->addressB.get()->getValue();
}

/**
 * Sets value of first address
 * @param i new value of first address
 */
void Instruction::setAValue(int i) {
    this->addressA.get()->setValue(i);
}


/**
 * Sets value of second address
 * @param i new value of second address
 */
void Instruction::setBValue(int i) {
    this->addressB.get()->setValue(i);
}

int Instruction::getLastMemoryIndex() const {
    return lastMemoryIndex;
}

void Instruction::setLastMemoryIndex(int lastMemoryIndex) {
    Instruction::lastMemoryIndex = lastMemoryIndex;
}


