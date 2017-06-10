#include "MarsOperation.h"
#include <iostream>

MarsOperation::MarsOperation(const std::string opCode) : opCode(opCode) {}

MarsOperation::MarsOperation() {}

const std::string &MarsOperation::getOpCode() const {
    return this->opCode;
}

