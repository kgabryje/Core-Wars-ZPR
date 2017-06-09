#include "MovOperation.h"
#include "ProcessActionContinue.h"

MovOperation::MovOperation() : MarsOperation(ParserConstants::INSTR_CODE_MOV) {

}

boost::shared_ptr<ProcessAction> MovOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    Instruction &i = operParams->getInstruction();
    i.addToBValue(num);
    return boost::shared_ptr<ProcessAction>(new ProcessActionContinue());
}

boost::shared_ptr<ProcessAction> MovOperation::runOperation(OperationParamsInstructions *operParams) {

    Instruction &first = operParams->getFirstInstruction();
    Instruction &second = operParams->getSecondInstruction();
    second.setOperation(first.getOperation());
    second.setAddressA(first.getAddressA().get()->clone());
    second.setAddressB(first.getAddressB().get()->clone());

    return boost::shared_ptr<ProcessAction>(new ProcessActionContinue());
}
