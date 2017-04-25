#include <iostream>
#include <logic/Player.h>
#include <logic/MarsResult.h>
#include "MarsSimulator.h"

void MarsSimulator::setPlayers(
        std::vector<Player> players) {
    this->players = players;

}

MarsResult MarsSimulator::doStuff() {
    testCounter++;
    for (auto const &player: players)
        player.test();
    return MarsResult();
}
