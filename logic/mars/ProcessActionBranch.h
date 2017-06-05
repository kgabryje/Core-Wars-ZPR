#ifndef CORE_WARS_ZPR_PROCESSACTIONBRANCH_H
#define CORE_WARS_ZPR_PROCESSACTIONBRANCH_H

#include "ProcessAction.h"

class ProcessActionBranch : public ProcessAction {
public:
    ProcessActionBranch(int branchAddress);

    int getBranchAddress() const;

    virtual void runAction(ProcessManager &manager) override;

private:
    int branchAddress;
};


#endif //CORE_WARS_ZPR_PROCESSACTIONBRANCH_H
