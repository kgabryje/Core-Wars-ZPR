#ifndef CORE_WARS_ZPR_INSTRUCTIONOPERATOR_H
#define CORE_WARS_ZPR_INSTRUCTIONOPERATOR_H


#include <string>

class InstructionOperator {
public:
    InstructionOperator();
    InstructionOperator(const std::string &modifier, int value);
    int getValue() const;

private:
    std::string modifier;
    int value;
};


#endif //CORE_WARS_ZPR_INSTRUCTIONOPERATOR_H
