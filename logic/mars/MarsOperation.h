#ifndef CORE_WARS_ZPR_OPERATION_H
#define CORE_WARS_ZPR_OPERATION_H

#include <string>
#include <boost/shared_ptr.hpp>
#include "ProcessAction.h"

class OperationParamsMixed;

class MarsOperation {
public:
    MarsOperation(const std::string opCode);

    MarsOperation();

    const std::string &getOpCode() const;

    virtual boost::shared_ptr<ProcessAction> runOperation(OperationParamsMixed *operParams)=0;

private:
    const std::string opCode;
};


#endif //CORE_WARS_ZPR_OPERATION_H
