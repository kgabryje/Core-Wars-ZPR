#ifndef CORE_WARS_ZPR_INSTRUCTION_H
#define CORE_WARS_ZPR_INSTRUCTION_H


#include <logic/CoreWarsConstants.h>
#include <boost/shared_ptr.hpp>
#include <logic/parser/InstructionModifier.h>
#include "MarsOperation.h"


class Instruction {
public:
    Instruction(const boost::shared_ptr<InstructionModifier> operatorA,
                const boost::shared_ptr<InstructionModifier> operatorB);

    Instruction(const boost::shared_ptr<MarsOperation> operation);

    Instruction(const boost::shared_ptr<MarsOperation> operation,
                const boost::shared_ptr<InstructionModifier> operatorA,
                const boost::shared_ptr<InstructionModifier> operatorB);

    const boost::shared_ptr<MarsOperation> &getOperation() const;

    void setOperation(const boost::shared_ptr<MarsOperation> &operation);

    const boost::shared_ptr<InstructionModifier> &getAddressA() const;

    void setAddressA(const boost::shared_ptr<InstructionModifier> &addressA);

    const boost::shared_ptr<InstructionModifier> &getAddressB() const;

    void setAddressB(const boost::shared_ptr<InstructionModifier> &addressB);

    void addToAValue(int i);

    void addToBValue(int i);

    int getAValue();

    int getBValue();

    void setAValue(int i);

    void setBValue(int i);

private:
    boost::shared_ptr<InstructionModifier> addressA;
    boost::shared_ptr<InstructionModifier> addressB;
    boost::shared_ptr<MarsOperation> operation;

};

#endif //CORE_WARS_ZPR_INSTRUCTION_H
