#include "Instruction.h"

Instruction::Instruction(const boost::shared_ptr<InstructionAddress> operatorA,
                         const boost::shared_ptr<InstructionAddress> operatorB) : addressA(
        operatorA), addressB(operatorB) {}

Instruction::Instruction(const std::string opCode) : opCode(opCode) {}

void Instruction::test() {
    printf("Test Instruction: aOper: %d, bOper: %d\n", addressA->getValue(), addressB->getValue());
}

const std::string &Instruction::getOpCode() const {
    return opCode;
}

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
