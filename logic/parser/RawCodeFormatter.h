#ifndef CORE_WARS_ZPR_RAWCODEFORMATTER_H
#define CORE_WARS_ZPR_RAWCODEFORMATTER_H

#include <string>
#include <vector>

class RawCodeFormatter {

public:
    std::vector<std::pair<int, std::string>> format(std::string stringToFormat);
private:
    std::vector<std::pair<int, std::string>> split(std::string stringToSplit);

    std::vector<std::pair<int, std::string>>
    deleteEmptyAndCommentedLines(std::vector<std::pair<int, std::string>> lines);

    std::string &trim(std::string &stringToTrim);

    std::vector<std::pair<int, std::string>> trimLines(std::vector<std::pair<int, std::string>>);

    bool isLineEmptyOrWhitespace(const std::string &line) const;

    bool isLineComment(const std::string &line) const;
};


#endif //CORE_WARS_ZPR_RAWCODEFORMATTER_H

