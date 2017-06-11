#include <iostream>
#include <boost/shared_ptr.hpp>
#include "MarsSimulator.h"
#include "OperationParamsInstructions.h"
#include "IterationResult.h"
#include <random>

void MarsSimulator::setWarriors(
        std::pair<std::vector<Instruction>, std::vector<Instruction>> instructions) {

    setWarrior(instructions.first, firstWarriorManager);
    setWarrior(instructions.second, secondWarriorManager);

}

IterationResult MarsSimulator::doStuff() {

    std::cout << "lol1" << std::endl;
    doIteration(firstWarriorManager);
    std::cout << "lol3" << std::endl;
    doIteration(secondWarriorManager);
    std::cout << "lol4" << std::endl;
    IterationResult result;
    std::cout << "lol4" << std::endl;
    checkIfGameOver(result);
    std::cout << "lol5" << std::endl;
    result.setFirstWarriorProcessesIndexes(firstWarriorManager.getProcesses());
    std::cout << "lol6" << std::endl;
    result.setSecondWarriorProcessesIndexes(secondWarriorManager.getProcesses());
    std::cout << "lol7" << std::endl;
    result.setMemoryArray(mars.getMemoryArray());
    std::cout << "lol8" << std::endl;

    return result;
}

void MarsSimulator::setWarrior(std::vector<Instruction> warrior, ProcessManager &warriorManager) {
    int beginAddress = getRandomMemoryAddress();
    mars.enterWarrior(beginAddress, warrior);
    warriorManager.setFirstProcess(beginAddress);
}

int MarsSimulator::getRandomMemoryAddress() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, MARSConstants::MEMORY_ARRAY_SIZE);

    return uni(rng);
}

void MarsSimulator::doIteration(ProcessManager &warriorManager) {
    MemoryIndex mi = warriorManager.getCurrentAddress();
    std::shared_ptr<OperationParams> operationParams = mars.execute(mi);
    std::shared_ptr<MarsOperation> operation = mars.getOperation(mi);
    OperationResult iterationResult = operationParams->accept(operation);
    iterationResult.getPrecessAction()->runAction(warriorManager);
    mars.editMemoryArray(iterationResult.getInstructions());
}

MarsSimulator::MarsSimulator() {

}

IterationResult &MarsSimulator::checkIfGameOver(IterationResult &result) {
    if (firstWarriorManager.getSize() == 0)
        result.setLooser(1);
    else if (secondWarriorManager.getSize() == 0)
        result.setLooser(2);
    return result;

}

