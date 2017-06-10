#ifndef CORE_WARS_ZPR_MAINCONTROLLER_H
#define CORE_WARS_ZPR_MAINCONTROLLER_H

#include <logic/mars/MarsSimulator.h>
#include <logic/view/ViewConnector.h>
#include <thread>
#include <chrono>

class MainController {

public:
    void run();

    MainController();

private:
    MarsSimulator mars;
    ViewConnector view;
    void initialize();

    void runMARS();
};


#endif //CORE_WARS_ZPR_MAINCONTROLLER_H
