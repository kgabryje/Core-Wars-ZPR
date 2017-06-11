#include <logic/mars/IterationResult.h>
#include <logic/view/ViewConnector.h>
#include <logic/ServerConnector.h>
#include <logic/view/Initializer.h>
#include "MainController.h"


MainController::MainController() {}

void MainController::run() {

    initialize();
    runMARS();
}

/**
 * Initializes MARS controller with Redcode instructions
 */
void MainController::initialize() {
    Initializer init;

    players.first = init.sendCodeRequestAndParse(ViewConstants::FIRST_PLAYER_CORRECT_CODE_MESSAGE);
    players.second = init.sendCodeRequestAndParse(ViewConstants::SECOND_PLAYER_CORRECT_CODE_MESSAGE);

    mars.setWarriors(std::pair<std::vector<Instruction>, std::vector<Instruction>>(players.first.getInstructions(),
                                                                                   players.second.getInstructions()));
}

/**
 * Main loop of c++ client
 */
void MainController::runMARS() {
    int iteration = 0;
    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        IterationResult result = mars.doStuff();
        addPlayerData(result);
        view.sendToView(result);
    }
}

IterationResult &MainController::addPlayerData(IterationResult &result) {
    if (result.getLooser()) {
        int i = result.getLooser().get();
        if (i == 1) {
            result.setPlayerName(players.first.getName());
            result.setWarriorName(players.first.getWarriorName());
        } else {
            result.setPlayerName(players.second.getName());
            result.setWarriorName(players.second.getWarriorName());
        }
        return result;
    }

}







