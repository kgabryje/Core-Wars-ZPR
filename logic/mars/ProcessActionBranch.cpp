#include "ProcessActionBranch.h"

ProcessActionBranch::ProcessActionBranch(int branchAddress) : branchAddress(branchAddress) {}

/**
 * Returns branch address
 * @return branchAddress
 */
MemoryIndex ProcessActionBranch::getBranchAddress() const {
    return branchAddress;
}

/**
 * Branches current instruction
 * @param manager
 */
void ProcessActionBranch::runAction(ProcessManager &manager) {
    manager.branchCurrentInstruction(getBranchAddress());
}
