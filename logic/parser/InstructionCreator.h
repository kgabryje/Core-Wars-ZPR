#ifndef CORE_WARS_ZPR_INSTRUCTIONCREATOR_H
#define CORE_WARS_ZPR_INSTRUCTIONCREATOR_H


#include <logic/mars/Instruction.h>
#include "InstructionData.h"
#include <boost/shared_ptr.hpp>

class InstructionCreator {

public:
    static Instruction tryCreate(InstructionData data);
};


#endif //CORE_WARS_ZPR_INSTRUCTIONCREATOR_H
