#include "InstructionOperator.h"

InstructionOperator::InstructionOperator(const std::string &modifier, int value) : modifier(modifier), value(value) {}

InstructionOperator::InstructionOperator() {

}

int InstructionOperator::getValue() const {
    return value;
}
