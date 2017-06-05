#include "ProcessActionRemove.h"
#include "ProcessManager.h"

void ProcessActionRemove::runAction(ProcessManager &manager) {
    manager.removeCurrentInstruction();
}