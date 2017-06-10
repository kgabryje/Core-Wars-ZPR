#include "MainController.h"
#include "Initializer.h"

void MainController::run() {
    vector<Instruction> result;
    initialize();
    while (1) {
        std::cout << "Iteracja: " << iteration << std::endl;
        iteration++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Test1" << std::endl;
        result = mars.doStuff();
        std::cout << "Test2" << std::endl;
        std::cout << "result size: " << result.size() << std::endl;
        sendResultDontWaitForResponse(result);
        std::cout << "Test3" << std::endl;
    }
}

void MainController::initialize() {
    Initializer init;
    vector<Instruction> firstWarrior = init.sendCodeRequestAndParse();

    //vector<Instruction> secondWarrior = init.sendCodeRequestAndParse();
    mars.setWarriors(firstWarrior);
}

void MainController::sendResultDontWaitForResponse(vector<Instruction> result) {

    MARS::GameInfo gameInfo;
    int counter = 0;
    for (Instruction i: result) {
        if (i.getOperation()->getOpCode() == "DAT")
            gameInfo.colorTable.push_back("blue");
        else {
            gameInfo.colorTable.push_back("red");
            counter++;
        }
    }

    ServerConnector::getInstance().setGameInfo(gameInfo);
    std::cout << "Iteracja: " << iteration << " Liczba instrukcji nie DAT: " << counter << endl;
}

MainController::MainController() {}


