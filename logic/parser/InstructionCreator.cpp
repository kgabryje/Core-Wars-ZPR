#include "InstructionCreator.h"
#include "OperationFactory.h"
#include "InstructionModifierCreator.h"

Instruction InstructionCreator::tryCreate(InstructionData data) {


    boost::shared_ptr<MarsOperation> operation = OperationFactory::createOperation(data.getCode());
    Instruction instr(operation);

    boost::shared_ptr<InstructionModifier> aAddress = InstructionModifierCreator::tryCreate(data.getA_field());

    instr.setAddressA(aAddress);
    boost::shared_ptr<InstructionModifier> bAddress;
    if (data.getB_field() != "") {
        bAddress = InstructionModifierCreator::tryCreate(data.getB_field());
    } else {
        bAddress = InstructionModifierCreator::createDefault();
    }
    instr.setAddressB(bAddress);

    return instr;
}

Instruction InstructionCreator::createDefault() {
    return InstructionCreator::tryCreate(InstructionData(ParserConstants::INSTR_CODE_DAT, "0", "0"));
}

