#include "MainController.h"
#include "Initializer.h"

void MainController::run() {
    int result;
    initialize();
    while (1) {
//        _sleep(100);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        result = mars.doStuff();
        sendResultDontWaitForResponse(result);
    }
}

void MainController::initialize() {
    Initializer init;
    vector<shared_ptr<Instruction>> instructions = init.sendCodeRequestAndParse();
    mars.setInstructions(instructions);
}

void MainController::sendResultDontWaitForResponse(int i) {
//connector.sendRefreshRequest(i);
}
