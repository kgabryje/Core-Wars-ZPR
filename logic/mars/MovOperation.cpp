#include "MovOperation.h"
#include "ProcessActionContinue.h"
#include "Instruction.h"
#include <iostream>

MovOperation::MovOperation() : MarsOperation(ParserConstants::INSTR_CODE_MOV) {

}

boost::shared_ptr<ProcessAction> MovOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    Instruction i = operParams->getInstruction();
    i.addToBValue(num);
    return boost::shared_ptr<ProcessAction>(new ProcessActionContinue());
}
