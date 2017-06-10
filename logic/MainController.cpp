#include "MainController.h"
#include "Initializer.h"

/**
 * Main loop of c++ client
 */
void MainController::run() {
    vector<Instruction> result;
    initialize();
    while (1) {
        iteration++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        result = mars.doStuff();
        sendResultDontWaitForResponse(result);
    }
}

/**
 * Initializes MARS controller with Redcode instructions
 */
void MainController::initialize() {
    Initializer init;
    vector<Instruction> instructions = init.sendCodeRequestAndParse();
    mars.setInstructions(instructions);
}

void MainController::sendResultDontWaitForResponse(vector<Instruction> result) {

    int counter = 0;
    for (Instruction i: result) {
        if (i.getOperation()->getOpCode() != "DAT")
            counter++;
    }
    std::cout << "Iteracja: " << iteration << " Liczba instrukcji nie DAT: " << counter << endl;

}

MainController::MainController() {}


