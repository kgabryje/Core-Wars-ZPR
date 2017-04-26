#ifndef CORE_WARS_ZPR_INSTRUCTION_H
#define CORE_WARS_ZPR_INSTRUCTION_H


#include "InstructionOperator.h"

class Instruction {
public:
    Instruction();
    Instruction(const InstructionOperator *operatorA, const InstructionOperator *operatorB);
    virtual void test();

private:
    const InstructionOperator *operatorA;
    const InstructionOperator *operatorB;

};


#endif //CORE_WARS_ZPR_INSTRUCTION_H
