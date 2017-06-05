#include "ProcessActionContinue.h"
#include "ProcessManager.h"

void ProcessActionContinue::runAction(ProcessManager &manager) {
    manager.proceedToNextInstruction();
}
