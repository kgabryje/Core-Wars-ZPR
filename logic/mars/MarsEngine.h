#ifndef CORE_WARS_ZPR_MARSENGINE_H
#define CORE_WARS_ZPR_MARSENGINE_H


#include "MemoryIndex.h"
#include "ProcessAction.h"
#include "Instruction.h"
#include "OperationParams.h"
#include <boost/optional.hpp>
#include <vector>


class MarsEngine {

public:
    MarsEngine();

    boost::shared_ptr<OperationParams> execute(MemoryIndex mIndex);

    const std::vector<Instruction> getMemoryArray();

    void enterWarrior(int beginAddres, std::vector<Instruction> code);

private:
    std::vector<Instruction> memoryArray;
};


#endif //CORE_WARS_ZPR_MARSENGINE_H
