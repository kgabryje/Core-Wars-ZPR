#ifndef CORE_WARS_ZPR_PROCESSACTIONREMOVE_H
#define CORE_WARS_ZPR_PROCESSACTIONREMOVE_H

#include "ProcessAction.h"

class ProcessActionRemove : public ProcessAction {
public:
    virtual void runAction(ProcessManager &manager) override;
};


#endif //CORE_WARS_ZPR_PROCESSACTIONREMOVE_H
