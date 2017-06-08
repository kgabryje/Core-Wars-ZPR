#ifndef CORE_WARS_ZPR_INSTRUCTIONFACTORY_H
#define CORE_WARS_ZPR_INSTRUCTIONFACTORY_H

#include "InstructionData.h"
#include "logic/mars/MarsOperation.h"
#include <boost/shared_ptr.hpp>

class OperationFactory {

public:
    static boost::shared_ptr<MarsOperation> createOperation(const string &data);
};


#endif //CORE_WARS_ZPR_INSTRUCTIONFACTORY_H
