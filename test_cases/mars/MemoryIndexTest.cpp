#include "test_cases/catch.hpp"
#include <logic/mars/MemoryIndex.h>
#include <logic/CoreWarsConstants.h>


SCENARIO("MemoryIndexTest: initializing memory array pointer") {
    WHEN("Given address is smaller than MEMORY_ARRAY_SIZE") {
        int address = 2;
        THEN("MemoryIndex is created with that address") {
            MemoryIndex m(address);
            REQUIRE(*m == address);
        }
    }

    WHEN("Given address is equal MEMORY_ARRAY_SIZE") {
        int addressEqual = MARSConstants::MEMORY_ARRAY_SIZE;
        THEN("MemoryIndex created with that address points to address 0") {
            MemoryIndex m(addressEqual);
            REQUIRE(*m == 0);
        }
    }

    WHEN("Given address is greater than MEMORY_ARRAY_SIZE") {
        int addressGreater = MARSConstants::MEMORY_ARRAY_SIZE + 3;
        THEN("MemoryIndex created with that address points to address % MEMORY_ARRAY_SIZE") {
            MemoryIndex m(addressGreater);
            REQUIRE(*m == 3);
        }
    }
}

SCENARIO("MemoryIndexTest: operating on memory array pointer") {
    int address = MARSConstants::MEMORY_ARRAY_SIZE - 3;
    MemoryIndex m(address);
    WHEN("Dereference operator is used") {
        THEN("MemoryIndex returns current value") {
            REQUIRE(*m == address);
        }
    }
    WHEN("Prefix increment operator is used") {
        int address = MARSConstants::MEMORY_ARRAY_SIZE - 3;
        MemoryIndex m(address);
        THEN("MemoryIndex is incremented before action") {
            REQUIRE(*(++m) == address + 1);
            REQUIRE(*(m) == address + 1);
        }
    }
    WHEN("Prefix increment operator is used") {
        int address = MARSConstants::MEMORY_ARRAY_SIZE - 3;
        MemoryIndex m(address);
        THEN("MemoryIndex is compared to int ") {
            REQUIRE(m == address);
            REQUIRE(++m == address + 1);
        }
    }
    WHEN("Postfix increment operator is used") {
        int address = MARSConstants::MEMORY_ARRAY_SIZE - 3;
        MemoryIndex m(address);
        THEN("MemoryIndex is incremented after action") {
            REQUIRE(*(m++) == address);
            REQUIRE(*(m) == address + 1);
        }
    }
    WHEN("Equal to operator is used") {
        int address = MARSConstants::MEMORY_ARRAY_SIZE - 3;
        MemoryIndex m(address);
        THEN("MemoryIndex is compared to int ") {
            REQUIRE(m == address);
            REQUIRE(++m == address + 1);
        }
    }
    WHEN("Memory index is incremented over MEMORY_ARRAY_SIZE") {
        THEN("Memory index becomes zero") {
            int address = MARSConstants::MEMORY_ARRAY_SIZE - 1;
            MemoryIndex m(address);
            REQUIRE(m == address);
            REQUIRE(++m == 0);
            REQUIRE(m == 0);
        }
    }
    WHEN("+ or += operator is used with positive number") {
        THEN("Memory index has correct value") {
            int address = MARSConstants::MEMORY_ARRAY_SIZE - 3;
            MemoryIndex m(address);
            REQUIRE(m == address);
            m += 2;
            REQUIRE(m == MARSConstants::MEMORY_ARRAY_SIZE - 1);
            MemoryIndex mi = m + 3;
            REQUIRE(m == MARSConstants::MEMORY_ARRAY_SIZE - 1);
            REQUIRE(mi == 2);
            mi += 2 * MARSConstants::MEMORY_ARRAY_SIZE + 1;
            REQUIRE(mi == 3);
        }
    }
    WHEN("+ or += operator is used with negative number") {
        THEN("Memory index has correct value") {
            int address = 3;
            MemoryIndex m(address);
            REQUIRE(m == address);
            m += -1;
            REQUIRE(m == 2);
            MemoryIndex mi = m + (-3);
            REQUIRE(mi == MARSConstants::MEMORY_ARRAY_SIZE - 1);
            mi += -(MARSConstants::MEMORY_ARRAY_SIZE + 1);
            REQUIRE(mi == MARSConstants::MEMORY_ARRAY_SIZE - 2);
        }
    }
    WHEN("- or -= operator is used with positive number") {
        THEN("Memory index has correct value") {
            int address = 3;
            MemoryIndex m(address);
            REQUIRE(m == address);
            m -= 2;
            REQUIRE(m == 1);
            MemoryIndex mi = m - 3;
            REQUIRE(m == 1);
            REQUIRE(mi == MARSConstants::MEMORY_ARRAY_SIZE - 2);
            mi -= (2 * MARSConstants::MEMORY_ARRAY_SIZE + 1);
            REQUIRE(mi == MARSConstants::MEMORY_ARRAY_SIZE - 3);
        }
    }
    WHEN("- or -= operator is used with negative number") {
        THEN("Memory index has correct value") {
            int address = MARSConstants::MEMORY_ARRAY_SIZE - 3;
            MemoryIndex m(address);
            REQUIRE(m == address);
            m -= -2;
            REQUIRE(m == MARSConstants::MEMORY_ARRAY_SIZE - 1);
            MemoryIndex mi = m - (-3);
            REQUIRE(m == MARSConstants::MEMORY_ARRAY_SIZE - 1);
            REQUIRE(mi == 2);
            mi -= -2 * (MARSConstants::MEMORY_ARRAY_SIZE + 1);
            REQUIRE(mi == 4);
        }
    }
}