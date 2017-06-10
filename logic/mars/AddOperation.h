#ifndef CORE_WARS_ZPR_ADDOPERATION_H
#define CORE_WARS_ZPR_ADDOPERATION_H

#include "MarsOperation.h"
#include "OperationParamsMixed.h"
#include "OperationParamsInstructions.h"
#include "OperationResult.h"

class AddOperation : public MarsOperation {
public:
    AddOperation();

    OperationResult runOperation(OperationParamsInstructions *operParams) override;

    virtual OperationResult runOperation(OperationParamsMixed *operParams);

    MarsOperation *clone() const override;
};

#endif //CORE_WARS_ZPR_ADDOPERATION_H
