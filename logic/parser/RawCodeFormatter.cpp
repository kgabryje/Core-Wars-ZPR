#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "RawCodeFormatter.h"

std::vector<std::string> RawCodeFormatter::format(std::string stringToFormat) {

    std::vector<std::string> lines = split(stringToFormat);
    lines = trimLines(lines);
    return deleteEmptyAndCommentedLines(lines);
}

std::vector<std::string> RawCodeFormatter::split(std::string stringToSplit) {

    std::istringstream rawCodeStream(stringToSplit);
    std::vector<std::string> lines;

    while (!rawCodeStream.eof()) {
        std::string s1;
        getline(rawCodeStream, s1);
        lines.push_back(s1);
    }

    return lines;
}

std::vector<std::string> RawCodeFormatter::deleteEmptyAndCommentedLines(std::vector<std::string> lines) {

    for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end();) {
        std::string line = *it;
        if (isLineEmptyOrWhitespace(line) || isLineComment(line)) {
            it = lines.erase(it);
        } else {
            ++it;
        }
    }

    return lines;
}

bool RawCodeFormatter::isLineComment(const std::string &line) const { return line[0] == ';'; }

bool RawCodeFormatter::isLineEmptyOrWhitespace(const std::string &line) const { return isspace(line[0]) || line==""; }

std::string &RawCodeFormatter::trim(std::string &stringToTrim) {

    stringToTrim.erase(0, stringToTrim.find_first_not_of(' '));
    stringToTrim.erase(stringToTrim.find_last_not_of(' ') + 1);
    return stringToTrim;
}

std::vector<std::string> RawCodeFormatter::trimLines(std::vector<std::string> lines) {

    for (std::string &line: lines) {
        trim(line);
    }
    return lines;
}

