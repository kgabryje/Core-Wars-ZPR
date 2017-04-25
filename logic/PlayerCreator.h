#ifndef CORE_WARS_ZPR_PLAYERCREATOR_H
#define CORE_WARS_ZPR_PLAYERCREATOR_H


#include <c++/vector>
#include <logic/view/ViewInput.h>
#include "Player.h"

class PlayerCreator {

public:
    static std::vector<Player> createPlayers(std::vector <ViewInput>);
};


#endif //CORE_WARS_ZPR_PLAYERCREATOR_H
