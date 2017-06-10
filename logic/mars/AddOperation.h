#ifndef CORE_WARS_ZPR_ADDOPERATION_H
#define CORE_WARS_ZPR_ADDOPERATION_H

#include "MarsOperation.h"
#include "OperationParamsMixed.h"
#include "OperationParamsInstructions.h"

class AddOperation : public MarsOperation {
public:
    AddOperation();

    std::shared_ptr<ProcessAction> runOperation(OperationParamsInstructions *operParams) override;

    virtual std::shared_ptr<ProcessAction> runOperation(OperationParamsMixed *operParams);
};

#endif //CORE_WARS_ZPR_ADDOPERATION_H
