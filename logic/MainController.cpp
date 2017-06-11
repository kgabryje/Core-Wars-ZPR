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

void MainController::initialize() {
    std::cout << "Mars starts running" << endl;
    Initializer init;

    players.first = init.sendCodeRequestAndParse(ViewConstants::FIRST_PLAYER_CORRECT_CODE_MESSAGE);
    std::cout << "got first player" << endl;
    players.second = init.sendCodeRequestAndParse(ViewConstants::SECOND_PLAYER_CORRECT_CODE_MESSAGE);
    std::cout << "got second player" << endl;

    mars.setWarriors(std::pair<std::vector<Instruction>, std::vector<Instruction>>(players.first.getInstructions(),
                                                                                   players.second.getInstructions()));
}

void MainController::runMARS() {
    int iteration = 0;
    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Iteration nr: " << ++iteration << endl;
        IterationResult result = mars.doStuff();
        int dats1 = 0;
        for (Instruction i : result.getMemoryArray())
            if (i.getOperation()->getOpCode() != "DAT")
                dats1++;
        std::cout << "Got result " << "NOT DATS num = " << dats1 << endl;
        //addPlayerData(result);
        std::cout << "Added player data" << endl;
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







