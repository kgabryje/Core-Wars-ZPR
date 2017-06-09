#include <logic/mars/MarsEngine.h>
#include "test_cases/catch.hpp"

SCENARIO("MarsEngineTest") {
    WHEN("Default constructor is fired") {
        MarsEngine mars;
        REQUIRE(mars.getMemoryArray().size() == MARSConstants::MEMORY_ARRAY_SIZE);
        const std::vector<Instruction> memory = mars.getMemoryArray();
        THEN("vector of proper size is created") {
            REQUIRE(memory.size() == MARSConstants::MEMORY_ARRAY_SIZE);

        }
        AND_THEN("vector is populated with DATS 0,0") {
            bool success = true;
            for (Instruction i : memory)
                if (i.getOperation()->getOpCode() != ParserConstants::INSTR_CODE_DAT) {
                    success = false;
                    break;
                }
            REQUIRE(success);
        }
    }
}