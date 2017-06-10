#ifndef CORE_WARS_ZPR_OPERATIONPARAMSMIXED_H
#define CORE_WARS_ZPR_OPERATIONPARAMSMIXED_H

#include "OperationParams.h"

class Instruction;

class OperationParamsMixed : public OperationParams {

public:
    OperationParamsMixed(int i, Instruction &instruction);

    int getValue() const;

    Instruction &getInstruction() const;

    virtual std::shared_ptr<ProcessAction> accept(std::shared_ptr<MarsOperation> shared_ptr);

private:
    int value;
    Instruction &instruction;
};


#endif //CORE_WARS_ZPR_OPERATIONPARAMSMIXED_H
