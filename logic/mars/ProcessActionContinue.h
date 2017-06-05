#ifndef CORE_WARS_ZPR_PROCESSACTIONCONTINUE_H
#define CORE_WARS_ZPR_PROCESSACTIONCONTINUE_H

#include "ProcessAction.h"

class ProcessActionContinue : public ProcessAction {
public:
    virtual void runAction(ProcessManager &manager) override;

};


#endif //CORE_WARS_ZPR_PROCESSACTIONCONTINUE_H
