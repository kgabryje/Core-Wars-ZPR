#include "./catch.hpp"
#include "../logic/parser/InstructionFactory.h"
#include "../logic/parser/InstructionData.h"
#include "../logic/mars/Instruction.h"
#include "../logic/mars/DatInstruction.h"
#include "../logic/parser/RedcodeParser.h"
#include "../logic/parser/ParserException.h"

TEST_CASE( "Unknown instruction type has been provided","[parser]" ) {
    const string code = "LOL";
    REQUIRE_THROWS(
            InstructionFactory::createInstruction(code)
    );
};

TEST_CASE( "Correct instruction type has been provided","[parser]" ) {
    const string code = "MOV";
    REQUIRE_NOTHROW(
            InstructionFactory::createInstruction(code)
    );
}

//TEST_CASE( "DAT instruction type results in correct object","[parser]" ) {
//    const string code = "DAT";
//    const string fieldA = "smth";
//    const string fieldB = "smth";
//    InstructionData instr(code, fieldA, fieldB);
//    std::shared_ptr<Instruction> instr_ptr = InstructionFactory::createInstruction(instr);
//    std::shared_ptr<DatInstruction> v = std::dynamic_pointer_cast<DatInstruction>(instr_ptr);
//    REQUIRE(
//        v.get() != NULL
//    );
//};

//TEST_CASE( "Parser returns always 5 elements","[parser]" ) {
//    RedcodeParser parser;
//    vector<shared_ptr<Instruction>> instr1 = parser.parse("DAT");
//    vector<shared_ptr<Instruction>> instr2 = parser.parse("MOV");
//    REQUIRE(
//        instr1.size() == 5
//    );
//    REQUIRE(
//        instr2.size() == 5
//    );
//};
//
//TEST_CASE("ParserException have const message", "[exception, parser]" ) {
//    try {
//       throw ParserException();
//    }
//    catch (const std::exception& e) {
//       REQUIRE(string("Problem has occurred during parsing") == string(e.what()));
//    }
//};
