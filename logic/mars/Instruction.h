#ifndef CORE_WARS_ZPR_INSTRUCTION_H
#define CORE_WARS_ZPR_INSTRUCTION_H


#include "InstructionOperator.h"
#include <logic/parser/CoreWarsConstants.h>

class Instruction {
public:
    Instruction(const std::string opCode);
    Instruction(const InstructionOperator *operatorA, const InstructionOperator *operatorB);
    virtual void test();

    const InstructionOperator *getOperatorA() const;

    void setOperatorA(const InstructionOperator *operatorA);

    const InstructionOperator *getOperatorB() const;

    void setOperatorB(const InstructionOperator *operatorB);

    const std::string &getOpCode() const;

private:
    const InstructionOperator *operatorA;
    const InstructionOperator *operatorB;
    const std::string opCode;
};

#endif //CORE_WARS_ZPR_INSTRUCTION_H
