#include "DatOperation.h"
#include <logic/CoreWarsConstants.h>

DatOperation::DatOperation() : MarsOperation(ParserConstants::INSTR_CODE_DAT) {

}

boost::shared_ptr<ProcessAction> DatOperation::runOperation(OperationParamsMixed *operParams) {
    return nullptr;
}

boost::shared_ptr<ProcessAction> DatOperation::runOperation(OperationParamsInstructions *operParams) {
    return nullptr;
}
