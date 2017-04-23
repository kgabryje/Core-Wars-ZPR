#ifndef CORE_WARS_ZPR_MAINCONTROLLER_H
#define CORE_WARS_ZPR_MAINCONTROLLER_H


#include <logic/mars/MarsSimulator.h>
#include "ServerConnector.h"
#include <thread>
#include <chrono>

class MainController {

public:
    void run();

private:
    MarsSimulator mars;
    ServerConnector connector;

    void initialize();
    void sendResultDontWaitForResponse(int i);
};


#endif //CORE_WARS_ZPR_MAINCONTROLLER_H
