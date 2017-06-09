#ifndef CORE_WARS_ZPR_PROCESSACTIONJUMP_H
#define CORE_WARS_ZPR_PROCESSACTIONJUMP_H


#include "ProcessAction.h"

class ProcessActionJump : public ProcessAction {
public:
    ProcessActionJump(int jump);

    int getJumpValue() const;

    virtual void runAction(ProcessManager &manager) override;

private:
    int jumpValue;
};

#endif //CORE_WARS_ZPR_PROCESSACTIONJUMP_H
