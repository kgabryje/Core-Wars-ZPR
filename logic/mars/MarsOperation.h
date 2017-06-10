#ifndef CORE_WARS_ZPR_OPERATION_H
#define CORE_WARS_ZPR_OPERATION_H

#include <string>
#include <boost/shared_ptr.hpp>
#include "ProcessAction.h"
#include "OperationResult.h"

class OperationParamsMixed;

class OperationResult;
class OperationParamsInstructions;

class MarsOperation {
public:
    MarsOperation(const std::string opCode);

    MarsOperation();

    const std::string &getOpCode() const;

    virtual OperationResult runOperation(OperationParamsMixed *operParams)=0;

    virtual OperationResult runOperation(OperationParamsInstructions *operParams)=0;

    virtual MarsOperation *clone() const = 0;
private:
    const std::string opCode;
};


#endif //CORE_WARS_ZPR_OPERATION_H
