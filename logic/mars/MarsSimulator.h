#ifndef CORE_WARS_ZPR_MARSSIMULATOR_H
#define CORE_WARS_ZPR_MARSSIMULATOR_H

#include <logic/MarsResult.h>
#include <c++/vector>
#include "Instruction.h"
#include <logic/Player.h>
class MarsSimulator {

public:
    void setPlayers(std::vector<Player> players);
    MarsResult doStuff();

private:
    int testCounter = 0;
    std::vector<Player> players;
};


#endif //CORE_WARS_ZPR_MARSSIMULATOR_H
