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
        if (i.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_DAT)
            gameInfo.colorTable.push_back(ViewConstants::INSTR_COLOR_DAT);
        else if (i.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_MOV)
            gameInfo.colorTable.push_back(ViewConstants::INSTR_COLOR_MOV);
        else if (i.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_JMP)
            gameInfo.colorTable.push_back(ViewConstants::INSTR_COLOR_JMP);
        else if (i.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_ADD)
            gameInfo.colorTable.push_back(ViewConstants::INSTR_COLOR_ADD);
    }

    ServerConnector::getInstance().setGameInfo(gameInfo);
}

MainController::MainController() {}


