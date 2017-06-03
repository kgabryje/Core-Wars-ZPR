//
// Created by kamil on 26.04.17.
//

#ifndef CORE_WARS_ZPR_MOVINSTRUCTION_H
#define CORE_WARS_ZPR_MOVINSTRUCTION_H

#include "Instruction.h"

class MovInstruction : public Instruction {
public:
    MovInstruction();

    MovInstruction(const boost::shared_ptr<InstructionAddress> operatorA,
                   const boost::shared_ptr<InstructionAddress> operatorB);
};


#endif //CORE_WARS_ZPR_MOVINSTRUCTION_H
