#include <logic/mars/IterationResult.h>
#include <logic/view/ViewConnector.h>
#include <logic/ServerConnector.h>
#include "MainController.h"
#include "Initializer.h"


MainController::MainController() {}

void MainController::run() {

    initialize();
    runMARS();
}

void MainController::initialize() {

    Initializer init;
    vector<Instruction> firstWarrior = init.sendCodeRequestAndParse("Kod jest poprawny. Wprowadź drugiego gracza");
    vector<Instruction> secondWarrior = init.sendCodeRequestAndParse("success");

    mars.setWarriors(std::pair<std::vector<Instruction>, std::vector<Instruction>>(firstWarrior, secondWarrior));
}

void MainController::runMARS() {
    while (1) {

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        IterationResult result = mars.doStuff();

        view.sendToView(result);
    }

}







