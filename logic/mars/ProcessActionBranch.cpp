#include "ProcessActionBranch.h"
#include "ProcessManager.h"

ProcessActionBranch::ProcessActionBranch(int branchAddress) : branchAddress(branchAddress) {}

int ProcessActionBranch::getBranchAddress() const {
    return branchAddress;
}

void ProcessActionBranch::runAction(ProcessManager &manager) {
    manager.branchCurrentInstruction(getBranchAddress());
}
