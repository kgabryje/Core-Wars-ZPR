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
        sendResultDontWaitForResponse(result);
        std::cout << "Test3" << std::endl;
    }
}

void MainController::initialize() {
    Initializer init;
    vector<Instruction> instructions = init.sendCodeRequestAndParse();
    mars.setInstructions(instructions);
}

void MainController::sendResultDontWaitForResponse(vector<Instruction> result) {

    std::vector<string> colors;
    int counter = 0;
    for (Instruction i: result) {
        if (i.getOperation()->getOpCode() == "DAT")
            colors.push_back("blue");
        else {
            colors.push_back("red");
            counter++;
        }
    }

    ServerConnector::getInstance().setColorTable(colors);
    std::cout << "Iteracja: " << iteration << " Liczba instrukcji nie DAT: " << counter << endl;

}

MainController::MainController() {}


