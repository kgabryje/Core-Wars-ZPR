#include "AddOperation.h"
#include "ProcessActionContinue.h"
#include <boost/make_shared.hpp>

AddOperation::AddOperation() : MarsOperation(ParserConstants::INSTR_CODE_ADD) {

}

std::shared_ptr<ProcessAction> AddOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    Instruction &i = operParams->getInstruction();
    i.addToBValue(num);
    return std::shared_ptr<ProcessAction>(new ProcessActionContinue());

}

std::shared_ptr<ProcessAction> AddOperation::runOperation(OperationParamsInstructions *operParams) {

    Instruction &first = (operParams->getFirstInstruction());
    Instruction &second = (operParams->getSecondInstruction());
    second.addToAValue(first.getAValue());
    second.addToBValue(first.getBValue());

    return std::shared_ptr<ProcessAction>(new ProcessActionContinue());
}
