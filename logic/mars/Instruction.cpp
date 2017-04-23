#include "Instruction.h"

Instruction::Instruction(const InstructionOperator *operatorA, const InstructionOperator *operatorB) : operatorA(
        operatorA), operatorB(operatorB) {}

void Instruction::test() {
    printf( "Test Instruction: aOper: %d, bOper: %d\n", operatorA->getValue(), operatorB->getValue() );
}