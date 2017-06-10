#ifndef CORE_WARS_ZPR_DATOPERATION_H
#define CORE_WARS_ZPR_DATOPERATION_H

#include "MarsOperation.h"

class DatOperation : public MarsOperation {
public:
    DatOperation();

    std::shared_ptr<ProcessAction> runOperation(OperationParamsInstructions *operParams) override;

    std::shared_ptr<ProcessAction> runOperation(OperationParamsMixed *operParams) override;
};


#endif //CORE_WARS_ZPR_DATOPERATION_H
