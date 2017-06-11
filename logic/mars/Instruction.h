#ifndef CORE_WARS_ZPR_INSTRUCTION_H
#define CORE_WARS_ZPR_INSTRUCTION_H


#include <logic/CoreWarsConstants.h>
#include <boost/shared_ptr.hpp>
#include <memory>
#include <logic/parser/InstructionModifier.h>
#include "MarsOperation.h"

class MarsOperation;
class InstructionModifier;

/**
 * Base class representing Instruction. A single Instruction consists of 2 operators and an operation
 */
class Instruction {
public:
    Instruction(const std::shared_ptr<InstructionModifier> operatorA,
                const std::shared_ptr<InstructionModifier> operatorB);

    Instruction(const std::shared_ptr<MarsOperation> operation);

    Instruction(const std::shared_ptr<MarsOperation> operation,
                const std::shared_ptr<InstructionModifier> operatorA,
                const std::shared_ptr<InstructionModifier> operatorB);

    const std::shared_ptr<MarsOperation> getOperation() const;

    void setOperation(const std::shared_ptr<MarsOperation> operation);

    const std::shared_ptr<InstructionModifier> getAddressA() const;

    void setAddressA(const std::shared_ptr<InstructionModifier> addressA);

    const std::shared_ptr<InstructionModifier> getAddressB() const;

    void setAddressB(const std::shared_ptr<InstructionModifier> addressB);

    void addToAValue(int i);

    void addToBValue(int i);

    int getAValue();

    int getBValue();

    void setAValue(int i);

    void setBValue(int i);

    int getLastMemoryIndex() const;

    void setLastMemoryIndex(int lastMemoryIndex);

private:
    std::shared_ptr<InstructionModifier> addressA;
    std::shared_ptr<InstructionModifier> addressB;
    std::shared_ptr<MarsOperation> operation;

    int lastMemoryIndex;

};

#endif //CORE_WARS_ZPR_INSTRUCTION_H
