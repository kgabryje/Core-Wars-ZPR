#include "InstructionCreator.h"
#include "InstructionFactory.h"

Instruction InstructionCreator::tryCreate(InstructionData data) {

    shared_ptr<Instruction> emptyInstruction = InstructionFactory::createInstruction(data.getCode());

    return *emptyInstruction.get();

}
