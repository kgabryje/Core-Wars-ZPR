#ifndef CORE_WARS_ZPR_OPERATIONPARAMS_H
#define CORE_WARS_ZPR_OPERATIONPARAMS_H

#include "ProcessAction.h"
#include "MarsOperation.h"
#include <boost/shared_ptr.hpp>

class OperationParams {

public:
    virtual std::shared_ptr<ProcessAction> accept(std::shared_ptr<MarsOperation> operation)=0;
};


#endif //CORE_WARS_ZPR_OPERATIONPARAMS_H
