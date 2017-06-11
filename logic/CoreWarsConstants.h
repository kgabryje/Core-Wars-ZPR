#ifndef CORE_WARS_ZPR_COREWARSCONSTANTS_H
#define CORE_WARS_ZPR_COREWARSCONSTANTS_H

#include <string>

namespace MARSConstants {
    const int MEMORY_ARRAY_SIZE(400);
}
namespace ViewConstants {

    const std::string INSTR_COLOR_DAT("blue");
    const std::string INSTR_COLOR_MOV("red");
    const std::string INSTR_COLOR_ADD("pink");
    const std::string INSTR_COLOR_JMP("green");
    const std::string FIRST_PLAYER_COLOR("white");
    const std::string SECOND_PLAYER_COLOR("black");
    const std::string FIRST_PLAYER_CORRECT_CODE_MESSAGE("Kod jest poprawny. Wprowadź drugiego gracza");
    const std::string SECOND_PLAYER_CORRECT_CODE_MESSAGE("success");
}

namespace ParserConstants {
    const std::string WRONG_SYNTAX_EXCEPTION("Wrong instruction syntax ");
    const std::string UKNOWN_CODE_EXCEPTION("Unknown instruction: ");
    const std::string UKNOWN_MODIFIER_EXCEPTION("Unknown address modifier: ");
    const std::string WRONG_NUMBER_EXCEPTION("Wrong format number: ");

    const std::string INSTR_CODE_DAT("DAT");
    const std::string INSTR_CODE_MOV("MOV");
    const std::string INSTR_CODE_ADD("ADD");
    const std::string INSTR_CODE_JMP("JMP");

    const char MODIFIER_IMMIDIATE = '#';
    const char MODIFIER_B_INDIRECT = '@';
    const char MODIFIER_DIRECT = '$';
}
#endif //CORE_WARS_ZPR_COREWARSCONSTANTS_H
