#ifndef CORE_WARS_ZPR_OPERATIONRESULT_H
#define CORE_WARS_ZPR_OPERATIONRESULT_H

#include "Instruction.h"

class Instruction;

class OperationResult {
    std::shared_ptr<ProcessAction> processAction;
    std::vector<Instruction> instructions;
public:
    const std::shared_ptr<ProcessAction> &getPrecessAction() const;

    void setPrecessAction(const std::shared_ptr<ProcessAction> &precessAction);

    const std::vector<Instruction> &getInstructions() const;

    void setInstructions(const std::vector<Instruction> &instructions);

    OperationResult(std::shared_ptr<ProcessAction> shared_ptr);

public:
    OperationResult(const std::shared_ptr<ProcessAction> &precessAction, const std::vector<Instruction> &instructions);
};


#endif //CORE_WARS_ZPR_OPERATIONRESULT_H
