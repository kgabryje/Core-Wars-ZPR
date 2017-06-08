#include "ProcessActionBranch.h"

ProcessActionBranch::ProcessActionBranch(int branchAddress) : branchAddress(branchAddress) {}

MemoryIndex ProcessActionBranch::getBranchAddress() const {
    return branchAddress;
}

void ProcessActionBranch::runAction(ProcessManager &manager) {
    manager.branchCurrentInstruction(getBranchAddress());
}
