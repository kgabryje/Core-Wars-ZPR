#include "Instruction.h"

Instruction::Instruction(const InstructionOperator *operatorA, const InstructionOperator *operatorB) : operatorA(
        operatorA), operatorB(operatorB) {}

Instruction::Instruction(const std::string opCode) : opCode(opCode) {}

void Instruction::test() {
    printf( "Test Instruction: aOper: %d, bOper: %d\n", operatorA->getValue(), operatorB->getValue() );
}

const InstructionOperator *Instruction::getOperatorA() const {
    return operatorA;
}

void Instruction::setOperatorA(const InstructionOperator *operatorA) {
    Instruction::operatorA = operatorA;
}

const InstructionOperator *Instruction::getOperatorB() const {
    return operatorB;
}

void Instruction::setOperatorB(const InstructionOperator *operatorB) {
    Instruction::operatorB = operatorB;
}