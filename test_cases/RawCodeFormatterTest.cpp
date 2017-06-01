#include <logic/parser/RawCodeFormatter.h>
#include "./catch.hpp"

using namespace std;

TEST_CASE("Provided text is splitted on new lines", "[parser]") {
    const string code1 = "To jest tekst podzielony";
    const string code2 = "znakami nowej linii";
    const string code = code1 +"\n" + code2;

    RawCodeFormatter r;
    std::vector<std::string> lines = r.format(code);

    REQUIRE(
            lines.size() == 2
    );
    REQUIRE(
            lines[0] == code1
    );
    REQUIRE(
            lines[1] == code2
    );

};
TEST_CASE("Provided text is splitted on new lines and  leading/trailing spaces are trimmed", "[parser]") {


    const string code1 = "Some text";
    const string code2 = "Even more text";
    const string code3 = "Wow much text";
    const string space = " ";
    const string code = space+space+code1 +"\n" + space+ code2 + "\n\n"+code3;

    RawCodeFormatter r;
    std::vector<std::string> lines = r.format(code);

    REQUIRE(
            lines.size() == 3
    );
    REQUIRE(
            lines[0] == code1
    );
    REQUIRE(
            lines[1] == code2
    );
    REQUIRE(
            lines[2] == code3
    );

};

TEST_CASE("Provided text is splitted on new lines, empty and whitespace lines are deleted", "[parser]") {


    const string code1 = "Some text";
    const string code2 = "Even more text";
    const string code3 = "Wow much text";
    const string space = " ";
    const string code = "\n"+ space +"\n"+"\t"+"\n"+code1 +"\n" + code2 + "\n"+"\n"+space+"\n"+code3;

    RawCodeFormatter r;
    std::vector<std::string> lines = r.format(code);

    REQUIRE(
            lines.size() == 3
    );
    REQUIRE(
            lines[0] == code1
    );
    REQUIRE(
            lines[1] == code2
    );
    REQUIRE(
            lines[2] == code3
    );

};

