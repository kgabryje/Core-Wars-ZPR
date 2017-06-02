#include "InstructionCreator.h"
#include "InstructionFactory.h"
#include "InstructionModifier.h"
#include "ModifierFactory.h"
#include "InstructionAddress.h"
#include "AddressCreator.h"

Instruction InstructionCreator::tryCreate(InstructionData data) {

    shared_ptr<Instruction> emptyInstruction = InstructionFactory::createInstruction(data.getCode());

    InstructionAddress aAddress = AddressCreator::tryCreate(data.getA_field());
    if (data.getB_field() != "") {}
    emptyInstruction->setOperatorB(AddressCreator::tryCreate(data.getB_field()));
}
    return *emptyInstruction.get();

}
