#ifndef CORE_WARS_ZPR_ITERATIONRESULT_H
#define CORE_WARS_ZPR_ITERATIONRESULT_H


#include "Instruction.h"

class IterationResult {
public:
    const std::vector<Instruction> &getResult() const;

    void setResult(const std::vector<Instruction> &result);

    const ProcessManager &getFirst() const;

    void setFirst(const ProcessManager &first);

    const ProcessManager &getSecond() const;

    void setSecond(const ProcessManager &second);

private:
    std::vector<Instruction> result;
    ProcessManager first;
    ProcessManager second;
};


#endif //CORE_WARS_ZPR_ITERATIONRESULT_H
