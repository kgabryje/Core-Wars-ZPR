#include "ProcessActionJump.h"

ProcessActionJump::ProcessActionJump(int jumpValue) : jumpValue(jumpValue) {}

/**
 * Returns jump value
 * @return jumpValue
 */
int ProcessActionJump::getJumpValue() const {
    return jumpValue;
}

/**
 * Jumps jumpValue instructions ahead
 * @param manager
 */
void ProcessActionJump::runAction(ProcessManager &manager) {
    manager.jumpFromCurrentInstruction(getJumpValue());
}
