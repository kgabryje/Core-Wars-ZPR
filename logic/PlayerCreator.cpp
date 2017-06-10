#include "PlayerCreator.h"

/**
 *
 * @param inputs
 * @return
 */
std::vector<Player> PlayerCreator::createPlayers(std::vector<ViewInput> inputs) {
    std::vector<Player> players;
    for (auto &input: inputs) {
        PlayerInfo pi(input.getPlayerName());
        Player p(pi);
        players.push_back(p);
    }
    return players;
}