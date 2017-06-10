#ifndef CORE_WARS_ZPR_DATOPERATION_H
#define CORE_WARS_ZPR_DATOPERATION_H

#include "MarsOperation.h"
#include "OperationResult.h"

class DatOperation : public MarsOperation {
public:
    DatOperation();

    OperationResult runOperation(OperationParamsInstructions *operParams) override;

    OperationResult runOperation(OperationParamsMixed *operParams) override;

    MarsOperation *clone() const override;
};


#endif //CORE_WARS_ZPR_DATOPERATION_H
