#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "RawCodeFormatter.h"

std::vector<std::pair<int, std::string>> RawCodeFormatter::format(std::string stringToFormat) {

    std::vector<std::pair<int, std::string>> lines = split(stringToFormat);
    lines = trimLines(lines);
    return deleteEmptyAndCommentedLines(lines);
}

std::vector<std::pair<int, std::string>> RawCodeFormatter::split(std::string stringToSplit) {

    std::istringstream rawCodeStream(stringToSplit);
    std::vector<std::pair<int, std::string>> lines;

    int i = 1;
    while (!rawCodeStream.eof()) {
        std::string s1;
        getline(rawCodeStream, s1);
        lines.push_back(std::pair<int, std::string>(i++, s1));
    }

    return lines;
}

std::vector<std::pair<int, std::string>>
RawCodeFormatter::deleteEmptyAndCommentedLines(std::vector<std::pair<int, std::string>> lines) {

    for (std::vector<std::pair<int, std::string>>::iterator it = lines.begin(); it != lines.end();) {
        std::string line = (*it).second;
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

std::vector<std::pair<int, std::string>> RawCodeFormatter::trimLines(std::vector<std::pair<int, std::string>> lines) {

    for (std::pair<int, std::string> &line: lines) {
        trim(line.second);
    }
    return lines;
}

