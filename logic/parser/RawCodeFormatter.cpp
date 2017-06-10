#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "RawCodeFormatter.h"

/**
 * Splits warrior code into lines, trims whitespaces and deletes commented or empty lines
 * @param stringToFormat Warrior code
 * @return vector of Redcode instructions and instruction numbers
 */
std::vector<std::pair<int, std::string>> RawCodeFormatter::format(std::string stringToFormat) {
    std::vector<std::pair<int, std::string>> lines = split(stringToFormat);
    lines = trimLines(lines);
    return deleteEmptyAndCommentedLines(lines);
}

/**
 * Splits warrior code into lines
 * @param stringToSplit Warrior code
 * @return vector of codelines and line numbers
 */
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

/**
 * Deletes empty or commented lines
 * @param lines vector of codelines and line numbers
 * @return formatted vector of instructions and line numbers
 */
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

/**
 * @param line line of warrior code
 * @return true if line is commented
 */
bool RawCodeFormatter::isLineComment(const std::string &line) const { return line[0] == ';'; }

/**
 *
 * @param line line of warrior code
 * @return true if line is empty or whitespace
 */
bool RawCodeFormatter::isLineEmptyOrWhitespace(const std::string &line) const { return isspace(line[0]) || line==""; }

/**
 * trims whitespaces on the borders of line
 * @param stringToTrim string to trim
 * @return trimmed string
 */
std::string &RawCodeFormatter::trim(std::string &stringToTrim) {

    stringToTrim.erase(0, stringToTrim.find_first_not_of(' '));
    stringToTrim.erase(stringToTrim.find_last_not_of(' ') + 1);
    return stringToTrim;
}

/**
 * Calls trim on lines of code
 * @param lines vector of lines of code and line numbers
 * @return trimmed lines of code
 */
std::vector<std::pair<int, std::string>> RawCodeFormatter::trimLines(std::vector<std::pair<int, std::string>> lines) {

    for (std::pair<int, std::string> &line: lines) {
        trim(line.second);
    }
    return lines;
}

