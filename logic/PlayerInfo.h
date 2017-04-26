#ifndef CORE_WARS_ZPR_PLAYERINFO_H
#define CORE_WARS_ZPR_PLAYERINFO_H


#include <string>

class PlayerInfo {
private:
    std::string name;
    int id;
    int color;

public:
    PlayerInfo(std::string &basic_string);
};


#endif //CORE_WARS_ZPR_PLAYERINFO_H