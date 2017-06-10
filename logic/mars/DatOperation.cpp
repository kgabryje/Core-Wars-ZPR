#include "DatOperation.h"
#include "ProcessActionRemove.h"
#include "OperationResult.h"
#include <logic/CoreWarsConstants.h>
#include <boost/make_shared.hpp>

DatOperation::DatOperation() : MarsOperation(ParserConstants::INSTR_CODE_DAT) {

}

OperationResult DatOperation::runOperation(OperationParamsMixed *operParams) {
    return std::shared_ptr<ProcessAction>(new ProcessActionRemove());
}

OperationResult DatOperation::runOperation(OperationParamsInstructions *operParams) {
    return std::shared_ptr<ProcessAction>(new ProcessActionRemove());
}

MarsOperation *DatOperation::clone() const {
    return new DatOperation(*this);
}
