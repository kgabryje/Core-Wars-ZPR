//
// Created by kamil on 26.04.17.
//

#ifndef CORE_WARS_ZPR_DATINSTRUCTION_H
#define CORE_WARS_ZPR_DATINSTRUCTION_H

#include "Instruction.h"
#include "InstructionOperator.h"

class DatInstruction : public Instruction {
public:
    DatInstruction(const InstructionOperator *operatorA, const InstructionOperator *operatorB);
};


#endif //CORE_WARS_ZPR_DATINSTRUCTION_H
