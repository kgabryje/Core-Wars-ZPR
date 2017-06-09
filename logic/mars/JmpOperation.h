#ifndef CORE_WARS_ZPR_JMPOPERATION_H
#define CORE_WARS_ZPR_JMPOPERATION_H

#include "MarsOperation.h"
#include "OperationParamsMixed.h"
#include "OperationParamsInstructions.h"


class JmpOperation : public MarsOperation {
public:
    JmpOperation();

    virtual boost::shared_ptr<ProcessAction> runOperation(OperationParamsInstructions *operParams) override;

    virtual boost::shared_ptr<ProcessAction> runOperation(OperationParamsMixed *operParams) override;
};


#endif //CORE_WARS_ZPR_JMPOPERATION_H
