#ifndef CORE_WARS_ZPR_VIEWCONNECTOR_H
#define CORE_WARS_ZPR_VIEWCONNECTOR_H


#include <logic/mars/Instruction.h>
#include <logic/mars/IterationResult.h>
#include <gen-cpp/mars_types.h>

class ViewConnector {

public:
    void sendToView(IterationResult result);

private:
    MARS::GameInfo gameInfo;

    void createViewData(const IterationResult &result);

    void colourOperations(const Instruction &i);

    void colourWarriorProcesses(int i, const std::string colour);

};


#endif //CORE_WARS_ZPR_VIEWCONNECTOR_H
