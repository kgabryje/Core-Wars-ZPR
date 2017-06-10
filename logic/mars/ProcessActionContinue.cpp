#include "ProcessActionContinue.h"

/**
 * Proceeds to next instruction
 * @param manager
 */
void ProcessActionContinue::runAction(ProcessManager &manager) {
    manager.proceedToNextInstruction();
}
