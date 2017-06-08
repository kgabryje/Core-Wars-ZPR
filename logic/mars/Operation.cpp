#include "Operation.h"

Operation::Operation(const std::string opCode) : opCode(opCode) {}

Operation::Operation() {}

const std::string &Operation::getOpCode() const {
    return this->opCode;
}
