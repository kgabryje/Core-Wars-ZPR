#include <logic/mars/ProcessManager.h>
#include <logic/mars/ProcessAction.h>
#include <logic/mars/ProcessActionContinue.h>
#include <logic/mars/ProcessActionBranch.h>
#include <logic/mars/ProcessActionRemove.h>
#include "test_cases/catch.hpp"

SCENARIO("ProcessManagerTest: managing processes") {
    GIVEN("ProcessManager and ProcessAction object") {
        int firstAddress = 9;
        ProcessManager pm(firstAddress);
        REQUIRE(
                pm.getCurrentAddress() == firstAddress
        );
        WHEN("Action is ActionBranch") {
            int firstBranchAddress = 21;
            ProcessAction *a = new ProcessActionBranch(firstBranchAddress);
            THEN("Current process address is INCREMENTED and moved at the end BEFORE newly added branch address") {
                a->runAction(pm);
                REQUIRE(
                        pm.getSize() == 2
                );
                REQUIRE(
                        pm.getCurrentAddress() == firstAddress + 1
                );
                AND_WHEN("Another branch is created") {
                    ProcessAction *a = new ProcessActionBranch(28);
                    THEN("3 processes are in queue and next address is firstBranchAddress") {
                        a->runAction(pm);
                        REQUIRE(
                                pm.getSize() == 3
                        );
                        REQUIRE(
                                pm.getCurrentAddress() == firstBranchAddress
                        );
                    }
                }
            }
        }
        GIVEN("Process queue: 11 - 33 - 23 - 37 ") {
            ProcessManager pm(firstAddress);
            int secondAddress = 22;
            int thirdAddress = 33;
            int fourthdAddress = 37;

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

                THEN("Current process incremented and is moved at the end") {
                    REQUIRE(
                            pm.getCurrentAddress() == firstAddress + 2
                    );
                    a->runAction(pm);
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
                            pm.getCurrentAddress() == firstAddress + 3
                    );
                    a->runAction(pm);
                    REQUIRE(
                            pm.getCurrentAddress() == thirdAddress + 1
                    );

                }
            }
            WHEN("Action is ActionRemove") {

                a = new ProcessActionRemove();

                THEN("Current process is killed") {
                    REQUIRE(
                            (pm.getCurrentAddress()) == firstAddress + 2
                    );
                    a->runAction(pm);
                    REQUIRE(
                            (pm.getCurrentAddress()) == thirdAddress
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
                            pm.getSize() == 0
                    );
                }
            }

        }
    }

}