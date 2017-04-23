#ifndef CORE_WARS_ZPR_INSTRUCTIONFACTORY_H
#define CORE_WARS_ZPR_INSTRUCTIONFACTORY_H

#include <memory>
#include "InstructionData.h"
#include "../mars/Instruction.h"

class InstructionFactory {

public:
    static std::shared_ptr<Instruction> createInstruction(const InstructionData &data);
};


#endif //CORE_WARS_ZPR_INSTRUCTIONFACTORY_H
