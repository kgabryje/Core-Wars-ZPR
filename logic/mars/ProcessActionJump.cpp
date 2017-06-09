#include "ProcessActionJump.h"

ProcessActionJump::ProcessActionJump(int jumpValue) : jumpValue(jumpValue) {}

int ProcessActionJump::getJumpValue() const {
    return jumpValue;
}

void ProcessActionJump::runAction(ProcessManager &manager) {
    manager.jumpFromCurrentInstruction(getJumpValue());
}
