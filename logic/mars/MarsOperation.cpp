#include "MarsOperation.h"
#include <iostream>

MarsOperation::MarsOperation(const std::string opCode) : opCode(opCode) {}

MarsOperation::MarsOperation() {}

const std::string &MarsOperation::getOpCode() const {
    return this->opCode;
}

//boost::shared_ptr<ProcessAction> MarsOperation::runOperation(OperationParams *operParams) {
//    std::cout<<"MarsOperation"<<std::endl;
//    return boost::shared_ptr<ProcessAction>();
//}
