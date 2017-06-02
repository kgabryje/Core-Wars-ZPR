#include "InstructionCreator.h"
#include "InstructionFactory.h"
#include "InstructionModifier.h"
#include "ModifierFactory.h"
#include "InstructionAddress.h"
#include "AddressCreator.h"

shared_ptr<Instruction> InstructionCreator::tryCreate(InstructionData data) {

    shared_ptr<Instruction> emptyInstruction = InstructionFactory::createInstruction(data.getCode());

    InstructionAddress *aAddress = AddressCreator::tryCreate(data.getA_field());

    emptyInstruction->setAddressA(boost::shared_ptr<InstructionAddress>(aAddress));

    if (data.getB_field() != "") {
        InstructionAddress *bAddress = AddressCreator::tryCreate(data.getB_field());
        emptyInstruction->setAddressB(boost::shared_ptr<InstructionAddress>(bAddress));
    }
    return emptyInstruction;
}

