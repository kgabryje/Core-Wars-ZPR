#ifndef CORE_WARS_ZPR_INSTRUCTIONFACTORY_H
#define CORE_WARS_ZPR_INSTRUCTIONFACTORY_H

#include "InstructionData.h"
#include "logic/mars/MarsOperation.h"
#include <boost/shared_ptr.hpp>

/**
 * Class managing creating instructions, implementing factory design pattern
 */
class OperationFactory {

public:
    static std::shared_ptr<MarsOperation> createOperation(const string &data);
};


#endif //CORE_WARS_ZPR_INSTRUCTIONFACTORY_H
