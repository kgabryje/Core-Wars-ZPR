#ifndef CORE_WARS_ZPR_MOVOPERATION_H
#define CORE_WARS_ZPR_MOVOPERATION_H

#include "MarsOperation.h"
#include "OperationParamsMixed.h"
#include "OperationParamsInstructions.h"
#include "OperationResult.h"

class MovOperation : public MarsOperation {
public:
    MovOperation();

    virtual OperationResult runOperation(OperationParamsInstructions *operParams) override;

    virtual OperationResult runOperation(OperationParamsMixed *operParams) override;

    MarsOperation *clone() const override;
};


#endif //CORE_WARS_ZPR_MOVOPERATION_H
