#include <logic/view/ViewInput.h>
#include "MainController.h"
#include "Initializer.h"

void MainController::run() {
    initialize();
    while (!isAppCancelled) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        MarsResult result = mars.doStuff();
        sendResultDontWaitForResponse(result);
    }
}

void MainController::initialize() {
    Initializer init;
    vector<Player> players = init.initialize();
    mars.setPlayers(players);
}

void MainController::sendResultDontWaitForResponse(MarsResult mr) {
//connector.sendRefreshRequest(i);
}
