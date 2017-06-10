#ifndef CORE_WARS_ZPR_OPERATION_H
#define CORE_WARS_ZPR_OPERATION_H

#include <string>
#include <boost/shared_ptr.hpp>
#include "ProcessAction.h"

class OperationParamsMixed;

class OperationParamsInstructions;

/**
 * Base class representing Operation
 */
class MarsOperation {
public:
    MarsOperation(const std::string opCode);

    MarsOperation();

    const std::string &getOpCode() const;

    virtual std::shared_ptr<ProcessAction> runOperation(OperationParamsMixed *operParams)=0;

    virtual std::shared_ptr<ProcessAction> runOperation(OperationParamsInstructions *operParams)=0;

private:
    const std::string opCode;
};


#endif //CORE_WARS_ZPR_OPERATION_H
