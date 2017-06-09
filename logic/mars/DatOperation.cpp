#include "DatOperation.h"
#include "ProcessActionRemove.h"
#include <logic/CoreWarsConstants.h>
#include <boost/make_shared.hpp>

DatOperation::DatOperation() : MarsOperation(ParserConstants::INSTR_CODE_DAT) {

}

boost::shared_ptr<ProcessAction> DatOperation::runOperation(OperationParamsMixed *operParams) {
    return boost::shared_ptr<ProcessAction>(new ProcessActionRemove());
}

boost::shared_ptr<ProcessAction> DatOperation::runOperation(OperationParamsInstructions *operParams) {
    return boost::shared_ptr<ProcessAction>(new ProcessActionRemove());
}
