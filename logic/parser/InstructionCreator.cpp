#include "InstructionCreator.h"
#include "InstructionFactory.h"
#include "AddressCreator.h"

shared_ptr<Instruction> InstructionCreator::tryCreate(InstructionData data) {

    shared_ptr<Instruction> instr = InstructionFactory::createInstruction(data.getCode());

    InstructionAddress *aAddress = AddressCreator::tryCreate(data.getA_field());

    instr->setAddressA(boost::shared_ptr<InstructionAddress>(aAddress));

    if (data.getB_field() != "") {
        InstructionAddress *bAddress = AddressCreator::tryCreate(data.getB_field());
        instr->setAddressB(boost::shared_ptr<InstructionAddress>(bAddress));
    }
    return instr;
}
