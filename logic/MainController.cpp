#include <logic/mars/IterationResult.h>
#include "MainController.h"
#include "Initializer.h"

void MainController::run() {
    IterationResult result;
    initialize();
    while (1) {
        std::cout << "Iteracja: " << iteration << std::endl;
        iteration++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        result = mars.doStuff();

        sendResultDontWaitForResponse(result);

    }
}

void MainController::initialize() {

    Initializer init;
    vector<Instruction> firstWarrior = init.sendCodeRequestAndParse("Kod jest poprawny. Wprowadź drugiego gracza");
    vector<Instruction> secondWarrior = init.sendCodeRequestAndParse("success");

    mars.setWarriors(std::pair<std::vector<Instruction>, std::vector<Instruction>>(firstWarrior, secondWarrior));
}

void MainController::sendResultDontWaitForResponse(IterationResult result) {

    MARS::GameInfo gameInfo;
    gameInfo.__set_firstPlayerProcessesNumber(result.getFirstWarriorProcessesIndexes().size());
    gameInfo.__set_secondPlayerProcessesNumber(result.getSecondWarriorProcessesIndexes().size());
    for (Instruction i: result.getMemoryArray()) {
        if (i.getOperation()->getOpCode() == "DAT")
            gameInfo.colorTable.push_back("blue");
        else if (i.getOperation()->getOpCode() == "MOV")
            gameInfo.colorTable.push_back("red");
        else if (i.getOperation()->getOpCode() == "JMP")
            gameInfo.colorTable.push_back("yellow");
        else if (i.getOperation()->getOpCode() == "ADD")
            gameInfo.colorTable.push_back("green");
    }

    ServerConnector::getInstance().setGameInfo(gameInfo);
}

MainController::MainController() {}


