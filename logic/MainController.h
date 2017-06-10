#ifndef CORE_WARS_ZPR_MAINCONTROLLER_H
#define CORE_WARS_ZPR_MAINCONTROLLER_H


#include <logic/mars/MarsSimulator.h>
#include "ServerConnector.h"
#include <thread>
#include <chrono>

class MainController {

public:
    void run();

    MainController();

private:
    MarsSimulator mars;
    void initialize();
    void sendResultDontWaitForResponse(std::vector<Instruction> result);

    int iteration = 0;
};


#endif //CORE_WARS_ZPR_MAINCONTROLLER_H
