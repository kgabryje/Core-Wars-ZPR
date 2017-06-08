#include "ProcessActionContinue.h"


void ProcessActionContinue::runAction(ProcessManager &manager) {
    manager.proceedToNextInstruction();
}
