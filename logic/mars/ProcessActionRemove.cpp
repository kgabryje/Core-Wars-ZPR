#include "ProcessActionRemove.h"
#include "ProcessManager.h"

/**
 * Removes current instruction
 * @param manager Process manager object reference
 */
void ProcessActionRemove::runAction(ProcessManager &manager) {
    manager.removeCurrentInstruction();
}