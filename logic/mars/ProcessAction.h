#ifndef CORE_WARS_ZPR_PROCESSACTION_H
#define CORE_WARS_ZPR_PROCESSACTION_H


#include "ProcessManager.h"

class ProcessAction {
public:
    virtual ~ProcessAction() {}
    virtual void runAction(ProcessManager &pm)=0;
};


#endif //CORE_WARS_ZPR_PROCESSACTION_H
