#ifndef CORE_WARS_ZPR_INSTRUCTIONCREATOR_H
#define CORE_WARS_ZPR_INSTRUCTIONCREATOR_H


#include <logic/mars/Instruction.h>
#include "InstructionData.h"

class InstructionCreator {

public:
    static shared_ptr<Instruction> tryCreate(InstructionData data);
};


#endif //CORE_WARS_ZPR_INSTRUCTIONCREATOR_H