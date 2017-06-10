#ifndef CORE_WARS_ZPR_JMPOPERATION_H
#define CORE_WARS_ZPR_JMPOPERATION_H

#include "MarsOperation.h"
#include "OperationParamsMixed.h"
#include "OperationParamsInstructions.h"
#include "OperationResult.h"


class JmpOperation : public MarsOperation {
public:
    JmpOperation();

    virtual OperationResult runOperation(OperationParamsInstructions *operParams) override;

    virtual OperationResult runOperation(OperationParamsMixed *operParams) override;

    MarsOperation *clone() const override;
};


#endif //CORE_WARS_ZPR_JMPOPERATION_H
