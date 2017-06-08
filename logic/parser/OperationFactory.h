#ifndef CORE_WARS_ZPR_INSTRUCTIONFACTORY_H
#define CORE_WARS_ZPR_INSTRUCTIONFACTORY_H

#include "InstructionData.h"
#include "../mars/Operation.h"
#include <boost/shared_ptr.hpp>

class OperationFactory {

public:
    static boost::shared_ptr<Operation> createOperation(const string &data);
};


#endif //CORE_WARS_ZPR_INSTRUCTIONFACTORY_H
