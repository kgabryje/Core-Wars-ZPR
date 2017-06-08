#ifndef CORE_WARS_ZPR_INSTRUCTION_H
#define CORE_WARS_ZPR_INSTRUCTION_H


#include <logic/CoreWarsConstants.h>
#include <boost/shared_ptr.hpp>
#include <logic/parser/InstructionModifier.h>
#include "Operation.h"

class Instruction {
public:
    Instruction(const boost::shared_ptr<InstructionModifier> operatorA,
                const boost::shared_ptr<InstructionModifier> operatorB);

    Instruction(const boost::shared_ptr<Operation> operation);

    Instruction(const boost::shared_ptr<Operation> operation, const boost::shared_ptr<InstructionModifier> operatorA,
                const boost::shared_ptr<InstructionModifier> operatorB);

    const boost::shared_ptr<Operation> &getOperation() const;

    void setOperation(const boost::shared_ptr<Operation> &operation);

    const boost::shared_ptr<InstructionModifier> &getAddressA() const;

    void setAddressA(const boost::shared_ptr<InstructionModifier> &addressA);

    const boost::shared_ptr<InstructionModifier> &getAddressB() const;

    void setAddressB(const boost::shared_ptr<InstructionModifier> &addressB);

private:
    boost::shared_ptr<InstructionModifier> addressA;
    boost::shared_ptr<InstructionModifier> addressB;
    boost::shared_ptr<Operation> operation;

};

#endif //CORE_WARS_ZPR_INSTRUCTION_H
