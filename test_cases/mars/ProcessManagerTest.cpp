#include <logic/mars/ProcessManager.h>
#include <logic/mars/ProcessAction.h>
#include <logic/mars/ProcessActionContinue.h>
#include <logic/mars/ProcessActionBranch.h>
#include <logic/mars/ProcessActionRemove.h>
#include "test_cases/catch.hpp"

SCENARIO("ProcessManagerTest: managing processes") {
    GIVEN("ProcessManager and ProcessAction object") {
        int firstAddress = 5;
        ProcessManager pm(firstAddress);
        WHEN("Action is ActionBranch") {
            ProcessAction *a = new ProcessActionBranch(10);
            THEN("Current instruction address is INCREMENTED and moved at the end AFTER newly added branch address") {
                a->runAction(pm);
                REQUIRE(
                        pm.getSize() == 2
                );
                REQUIRE(
                        pm.getCurrentAddress() == 10
                );
                AND_WHEN("Another branch is created") {
                    ProcessAction *a = new ProcessActionBranch(456);
                    THEN("3 processes in queue and next address is firstAddress + 1") {
                        a->runAction(pm);
                        REQUIRE(
                                pm.getSize() == 3
                        );
                        REQUIRE(
                                pm.getCurrentAddress() == firstAddress + 1
                        );
                    }
                }
            }
        }
        GIVEN("Process queue: 33 - 23 - 44 - 7") {
            int secondAddress = 22;
            int thirdAddress = 33;
            int fourthdAddress = 44;
            ProcessAction *a = new ProcessActionBranch(secondAddress);
            a->runAction(pm);
            a = new ProcessActionBranch(thirdAddress);
            a->runAction(pm);
            a = new ProcessActionBranch(fourthdAddress);
            a->runAction(pm);
            REQUIRE(
                    pm.getSize() == 4
            );
            WHEN("Action is ActionContinue") {
                ProcessAction *a = new ProcessActionContinue();


                THEN("Current instruction incremented and is moved at the end") {
                    REQUIRE(
                            pm.getCurrentAddress() == thirdAddress
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == secondAddress + 1
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == fourthdAddress
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == firstAddress + 2
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == thirdAddress + 1
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == secondAddress + 2
                    );

                }
            }
            WHEN("Action is ActionRemove") {
                ProcessAction *a = new ProcessActionRemove();


                THEN("Current instruction incremented and is moved at the end") {
                    REQUIRE(
                            pm.getCurrentAddress() == thirdAddress
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == secondAddress + 1
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == fourthdAddress
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == firstAddress + 2
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getSize() == 0
                    );
                }
            }

        }
    }
}