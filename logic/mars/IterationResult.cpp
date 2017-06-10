#include "IterationResult.h"

const std::vector<Instruction> &IterationResult::getResult() const {
    return result;
}

void IterationResult::setResult(const std::vector<Instruction> &result) {
    IterationResult::result = result;
}

const ProcessManager &IterationResult::getFirst() const {
    return first;
}

void IterationResult::setFirst(const ProcessManager &first) {
    IterationResult::first = first;
}

const ProcessManager &IterationResult::getSecond() const {
    return second;
}

void IterationResult::setSecond(const ProcessManager &second) {
    IterationResult::second = second;
}
