#ifndef CORE_WARS_ZPR_INSTRUCTION_H
#define CORE_WARS_ZPR_INSTRUCTION_H


#include <logic/CoreWarsConstants.h>
#include <boost/shared_ptr.hpp>
#include <logic/parser/InstructionAddress.h>

class Instruction {
public:
    Instruction(const std::string opCode);

    Instruction(const boost::shared_ptr<InstructionAddress> operatorA,
                const boost::shared_ptr<InstructionAddress> operatorB);
    virtual void test();

    const std::string &getOpCode() const;

    const boost::shared_ptr<InstructionAddress> &getAddressA() const;

    void setAddressA(const boost::shared_ptr<InstructionAddress> &addressA);

    const boost::shared_ptr<InstructionAddress> &getAddressB() const;

    void setAddressB(const boost::shared_ptr<InstructionAddress> &addressB);

private:
    boost::shared_ptr<InstructionAddress> addressA;
    boost::shared_ptr<InstructionAddress> addressB;
    const std::string opCode;
};

#endif //CORE_WARS_ZPR_INSTRUCTION_H
