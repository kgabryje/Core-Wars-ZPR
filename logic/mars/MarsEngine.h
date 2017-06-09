#ifndef CORE_WARS_ZPR_MARSENGINE_H
#define CORE_WARS_ZPR_MARSENGINE_H


#include "MemoryIndex.h"
#include "ProcessAction.h"
#include "Instruction.h"


class MarsEngine {
private:
    std::vector<Instruction> memoryArray;
public:
    MarsEngine();

public:
    const ProcessAction &execute(MemoryIndex mIndex);

    const std::vector<Instruction> getMemoryArray();
};


#endif //CORE_WARS_ZPR_MARSENGINE_H
