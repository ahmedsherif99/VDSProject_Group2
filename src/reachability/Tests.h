#ifndef VDSPROJECT_REACHABILITY_TESTS_H
#define VDSPROJECT_REACHABILITY_TESTS_H

#include <gtest/gtest.h>
#include "Reachability.h"
#include "../Manager.h"

using namespace ClassProject;

struct ReachabilityTest : testing::Test {

    std::unique_ptr<ClassProject::ReachabilityInterface> fsm2 = std::make_unique<ClassProject::Reachability>(2,2);

    std::vector<BDD_ID> stateVars2 = fsm2->getStates();
    std::vector<BDD_ID> inputVars2 = fsm2->getInputs();
    std::vector<BDD_ID> transitionFunctions;

};

TEST_F(ReachabilityTest, HowTo_Example) { /* NOLINT */

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->neg(s0));
    transitionFunctions.push_back(fsm2->neg(s1));
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false,false});

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_FALSE(fsm2->isReachable({false, true}));
    ASSERT_FALSE(fsm2->isReachable({true, false}));
    ASSERT_TRUE(fsm2->isReachable({true, true}));
}

TEST_F(ReachabilityTest, HowTo_Example2) { /* NOLINT */

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);
    BDD_ID i0 = inputVars2.at(0);
    BDD_ID i1 = inputVars2.at(1);

    transitionFunctions.push_back(fsm2->or2(fsm2->neg(s0),i0)); // s0' = not(s0)+i0
    transitionFunctions.push_back(fsm2->neg(s1)); // s1' = not(s1) 1 0
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false,false,false,false});

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_FALSE(fsm2->isReachable({false, true}));
    ASSERT_FALSE(fsm2->isReachable({true, false}));
    ASSERT_TRUE(fsm2->isReachable({true, true}));

    
}

TEST_F(ReachabilityTest, HowTo_Example3) { /* NOLINT */

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);
    BDD_ID i0 = inputVars2.at(0);
    BDD_ID i1 = inputVars2.at(1);

    transitionFunctions.push_back(fsm2->or2(fsm2->neg(s0),i0)); // s0' = not(s0)+i0
    transitionFunctions.push_back(fsm2->neg(s1)); // s1' = not(s1) 1 0
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false,false,true,false});

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_TRUE(fsm2->isReachable({false, true}));
    ASSERT_TRUE(fsm2->isReachable({true, false}));
    ASSERT_TRUE(fsm2->isReachable({true, true}));

    
}

TEST_F(ReachabilityTest, HowTo_Example4) { /* NOLINT */

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->xor2(s0,s1)); // s0' = not(s0)+i0
    transitionFunctions.push_back(fsm2->neg(s1)); // s1' = not(s1)
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false,false});

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_TRUE(fsm2->isReachable({false, true}));
    ASSERT_TRUE(fsm2->isReachable({true, false}));
    ASSERT_TRUE(fsm2->isReachable({true, true}));
}

struct InputReachabilityTest : testing::Test {
    std::unique_ptr<ClassProject::ReachabilityInterface> fsm = std::make_unique<ClassProject::Reachability>(2, 1);

    std::vector<BDD_ID> stateVars = fsm->getStates();
    std::vector<BDD_ID> inputVars = fsm->getInputs();
    std::vector<BDD_ID> transitionFunctions;

    BDD_ID s0 = stateVars[0];
    BDD_ID s1 = stateVars[1];
    BDD_ID x0 = inputVars[0];

};

TEST_F(InputReachabilityTest, InputTest){
    int NOT_REACHABLE = -1;
    // d1 = (!s0)x1
    transitionFunctions.push_back(fsm->and2(s0, x0));
    transitionFunctions.push_back(true);
    fsm->setTransitionFunctions(transitionFunctions);

    fsm->setInitState({false, true});
    EXPECT_FALSE(fsm->isReachable({false, false}));
}
#endif
