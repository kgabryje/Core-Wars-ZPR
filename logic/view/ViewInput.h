#ifndef CORE_WARS_ZPR_VIEWINPUT_H
#define CORE_WARS_ZPR_VIEWINPUT_H


#include <c++/string>

class ViewInput {
private:
     std::string playerName;
     std::string warriorName;
     std::string warriorCode;
public:
    ViewInput( std::string &playerName,  std::string &warriorName,  std::string &warriorCode);

     std::string &getPlayerName() ;

    void setPlayerName( std::string &playerName);

     std::string &getWarriorName() ;

    void setWarriorName( std::string &warriorName);

     std::string &getWarriorCode() ;

    void setWarriorCode( std::string &warriorCode);
};


#endif //CORE_WARS_ZPR_VIEWINPUT_H
