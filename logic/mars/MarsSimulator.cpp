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

    doIteration(firstWarriorManager);
    doIteration(secondWarriorManager);
    IterationResult result;
    result.setFirst(firstWarriorManager);
    result.setSecond(secondWarriorManager);
    result.setResult(mars.getMemoryArray());
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
    int i = 0;
    std::cout << i++ << std::endl;//0
    MemoryIndex mi = warriorManager.getCurrentAddress();
    std::cout << i++ << std::endl;//1
    std::shared_ptr<OperationParams> operationParams = mars.execute(mi);
    std::cout << i++ << std::endl;//2
    std::shared_ptr<MarsOperation> operation = mars.getOperation(mi);
    std::cout << i++ << std::endl;//3
    OperationResult iterationResult = operationParams->accept(operation);
    std::cout << i++ << std::endl;//4
    iterationResult.getPrecessAction()->runAction(warriorManager);
    std::cout << i++ << std::endl;//5
    mars.editMemoryArray(iterationResult.getInstructions());
}

MarsSimulator::MarsSimulator() {

}

