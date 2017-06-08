#ifndef CORE_WARS_ZPR_MOVOPERATION_H
#define CORE_WARS_ZPR_MOVOPERATION_H

#include "MarsOperation.h"
#include "OperationParamsMixed.h"

class MovOperation : public MarsOperation {
public:
    MovOperation();

    virtual boost::shared_ptr<ProcessAction> runOperation(OperationParamsMixed *operParams);
};


#endif //CORE_WARS_ZPR_MOVOPERATION_H
