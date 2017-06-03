//
// Created by kamil on 26.04.17.
//

#ifndef CORE_WARS_ZPR_DATINSTRUCTION_H
#define CORE_WARS_ZPR_DATINSTRUCTION_H

#include "Instruction.h"

class DatInstruction : public Instruction {
public:
    DatInstruction();

    DatInstruction(const boost::shared_ptr<InstructionAddress> operatorA,
                   const boost::shared_ptr<InstructionAddress> operatorB);
};


#endif //CORE_WARS_ZPR_DATINSTRUCTION_H
