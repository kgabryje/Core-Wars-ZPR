#ifndef CORE_WARS_ZPR_COREWARSCONSTANTS_H
#define CORE_WARS_ZPR_COREWARSCONSTANTS_H

#include <string>

namespace ParserConstants {
    const std::string WRONG_SYNTAX_EXCEPTION("Zła składnia w linii: ");
    const std::string UKNOWN_CODE_EXCEPTION("Nieznana instrukcja: ");;
    const std::string UKNOWN_MODIFIER_EXCEPTION("Nieznany modyfikator: ");;
    const std::string WRONG_NUMBER_EXCEPTION("Błędny format liczby w wyrażeniu: ");;

    const std::string INSTR_CODE_DAT("DAT");
    const std::string INSTR_CODE_MOV("MOV");

    const char MODIFIER_IMMIDIATE = '#';
    const char MODIFIER_B_INDIRECT = '@';
    const char MODIFIER_DIRECT = '$';
}
#endif //CORE_WARS_ZPR_COREWARSCONSTANTS_H
