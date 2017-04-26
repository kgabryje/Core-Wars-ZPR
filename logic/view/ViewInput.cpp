#include <string>
#include "logic/view/ViewInput.h"
#include "ViewInput.h"


ViewInput::ViewInput( std::string &playerName,  std::string &warriorName,  std::string &warriorCode)
        : playerName(playerName), warriorName(warriorName), warriorCode(warriorCode) {}

std::string &ViewInput::getPlayerName()  {
    return playerName;
}

std::string &ViewInput::getWarriorName()  {
    return warriorName;
}

std::string &ViewInput::getWarriorCode()  {
    return warriorCode;
}