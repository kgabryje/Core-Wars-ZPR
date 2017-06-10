#include "DatOperation.h"
#include "ProcessActionRemove.h"
#include <logic/CoreWarsConstants.h>

DatOperation::DatOperation() : MarsOperation(ParserConstants::INSTR_CODE_DAT) {

}

std::shared_ptr<ProcessAction> DatOperation::runOperation(OperationParamsMixed *operParams) {
    return std::shared_ptr<ProcessAction>(new ProcessActionRemove());
}

std::shared_ptr<ProcessAction> DatOperation::runOperation(OperationParamsInstructions *operParams) {
    return std::shared_ptr<ProcessAction>(new ProcessActionRemove());
}
