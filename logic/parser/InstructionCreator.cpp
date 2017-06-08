#include "InstructionCreator.h"
#include "OperationFactory.h"
#include "AddressCreator.h"

Instruction InstructionCreator::tryCreate(InstructionData data) {


    boost::shared_ptr<Operation> operation = OperationFactory::createOperation(data.getCode());
    Instruction instr(operation);

    InstructionAddress *aAddress = AddressCreator::tryCreate(data.getA_field());

    instr.setAddressA(boost::shared_ptr<InstructionAddress>(aAddress));
    InstructionAddress *bAddress;
    if (data.getB_field() != "") {
        bAddress = AddressCreator::tryCreate(data.getB_field());
    } else {
        bAddress = AddressCreator::createDefault();
    }
    instr.setAddressB(boost::shared_ptr<InstructionAddress>(bAddress));

    return instr;
}

