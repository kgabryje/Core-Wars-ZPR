#include "test_cases/catch.hpp"
#include <logic/parser/RawCodeFormatter.h>

using namespace std;

TEST_CASE("Provided text is splitted on new lines", "[parser]") {
    const string code1 = "To jest tekst podzielony";
    const string code2 = "znakami nowej linii";
    const string code = code1 + "\n" + code2;

    RawCodeFormatter r;
    std::vector<std::pair<int, std::string>> lines = r.format(code);

    REQUIRE(
            lines.size() == 2
    );
    REQUIRE(
            lines[0].second == code1
    );
    REQUIRE(
            lines[0].first == 1
    );
    REQUIRE(
            lines[1].second == code2
    );
    REQUIRE(
            lines[1].first == 2
    );

};

TEST_CASE("Provided text is splitted on new lines and  leading/trailing spaces are trimmed", "[parser]") {


    const string code1 = "Some text";
    const string code2 = "Even more text";
    const string code3 = "Wow much text";
    const string space = " ";
    const string code = space + space + code1 + "\n" + space + code2 + "\n" + code3;

    RawCodeFormatter r;
    std::vector<std::pair<int, std::string>> lines = r.format(code);

    REQUIRE(
            lines.size() == 3
    );
    REQUIRE(
            lines[0].second == code1
    );
    REQUIRE(
            lines[0].first == 1
    );
    REQUIRE(
            lines[1].second == code2
    );
    REQUIRE(
            lines[1].first == 2
    );
    REQUIRE(
            lines[2].second == code3
    );
    REQUIRE(
            lines[2].first == 3
    );

};

TEST_CASE("Provided text is splitted on new lines, empty and whitespace lines are deleted", "[parser]") {


    const string code1 = "Some text";
    const string code2 = "Even more text";
    const string code3 = "Wow much text";
    const string space = " ";
    const string code = "\n" + space + "\n" + "\t" + "\n" + code1 + "\n" + code2 + "\n" + "\n" + space + "\n" + code3;

    RawCodeFormatter r;
    std::vector<std::pair<int, std::string>> lines = r.format(code);

    REQUIRE(
            lines.size() == 3
    );
    REQUIRE(
            lines[0].second == code1
    );
    REQUIRE(
            lines[0].first == 4
    );
    REQUIRE(
            lines[1].second == code2
    );
    REQUIRE(
            lines[1].first == 5
    );
    REQUIRE(
            lines[2].second == code3
    );
    REQUIRE(
            lines[2].first == 8
    );

};

