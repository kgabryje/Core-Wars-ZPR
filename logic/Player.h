#ifndef CORE_WARS_ZPR_PLAYERS_H
#define CORE_WARS_ZPR_PLAYERS_H


#include "PlayerInfo.h"
#include <iostream>

class Player {
public:
    Player(PlayerInfo &info);

    void test()const;

private:
    const PlayerInfo info;

};


#endif //CORE_WARS_ZPR_PLAYERS_H