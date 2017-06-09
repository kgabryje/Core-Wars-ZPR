#include "AddOperation.h"
#include "ProcessActionContinue.h"
#include <boost/make_shared.hpp>

AddOperation::AddOperation() : MarsOperation(ParserConstants::INSTR_CODE_ADD) {

}

boost::shared_ptr<ProcessAction> AddOperation::runOperation(OperationParamsMixed *operParams) {
    int num = operParams->getValue();
    Instruction &i = operParams->getInstruction();
    i.addToBValue(num);
    return boost::shared_ptr<ProcessAction>(new ProcessActionContinue());

}

boost::shared_ptr<ProcessAction> AddOperation::runOperation(OperationParamsInstructions *operParams) {

    Instruction &first = (operParams->getFirstInstruction());
    Instruction &second = (operParams->getSecondInstruction());
    second.addToAValue(first.getAValue());
    second.addToBValue(first.getBValue());

    return boost::shared_ptr<ProcessAction>(new ProcessActionContinue());
}
