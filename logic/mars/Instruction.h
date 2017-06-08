#ifndef CORE_WARS_ZPR_INSTRUCTION_H
#define CORE_WARS_ZPR_INSTRUCTION_H


#include <logic/CoreWarsConstants.h>
#include <boost/shared_ptr.hpp>
#include <logic/parser/InstructionAddress.h>
#include "Operation.h"

class Instruction {
public:
    Instruction(const boost::shared_ptr<InstructionAddress> operatorA,
                const boost::shared_ptr<InstructionAddress> operatorB);

    Instruction(const boost::shared_ptr<Operation> operation);

    Instruction(const boost::shared_ptr<Operation> operation, const boost::shared_ptr<InstructionAddress> operatorA,
                const boost::shared_ptr<InstructionAddress> operatorB);

    const boost::shared_ptr<Operation> &getOperation() const;

    void setOperation(const boost::shared_ptr<Operation> &operation);

    const boost::shared_ptr<InstructionAddress> &getAddressA() const;

    void setAddressA(const boost::shared_ptr<InstructionAddress> &addressA);

    const boost::shared_ptr<InstructionAddress> &getAddressB() const;

    void setAddressB(const boost::shared_ptr<InstructionAddress> &addressB);

private:
    boost::shared_ptr<InstructionAddress> addressA;
    boost::shared_ptr<InstructionAddress> addressB;
    boost::shared_ptr<Operation> operation;

};

#endif //CORE_WARS_ZPR_INSTRUCTION_H
