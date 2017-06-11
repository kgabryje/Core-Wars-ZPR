#ifndef CORE_WARS_ZPR_VIEWCONNECTOR_H
#define CORE_WARS_ZPR_VIEWCONNECTOR_H

#include <logic/ServerConnector.h>
#include <logic/mars/Instruction.h>
#include <logic/mars/IterationResult.h>
#include <gen-cpp/mars_types.h>

class ViewConnector {
public:
    void colourOperations(const Instruction &i);

    void colourWarriorProcesses(int i, const std::string colour);

    void sendToView(IterationResult result);

private:
    MARS::GameInfo gameInfo;

    void createViewData(const IterationResult &result);
};


#endif //CORE_WARS_ZPR_VIEWCONNECTOR_H
