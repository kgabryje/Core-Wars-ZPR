#ifndef CORE_WARS_ZPR_OPERATIONPARAMSINSTRUCTIONS_H
#define CORE_WARS_ZPR_OPERATIONPARAMSINSTRUCTIONS_H

#include "OperationParams.h"
#include "Instruction.h"

class Instruction;

class OperationParamsInstructions : public OperationParams {

public:
    Instruction &getFirstInstruction() const;

    Instruction &getSecondInstruction() const;

    OperationParamsInstructions(Instruction instructionFirst, Instruction instructionSecond);

    boost::shared_ptr<ProcessAction> accept(boost::shared_ptr<MarsOperation> operation) override;

private:
    Instruction &firstInstruction;
    Instruction &secondInstruction;
};


#endif //CORE_WARS_ZPR_OPERATIONPARAMSINSTRUCTIONS_H
