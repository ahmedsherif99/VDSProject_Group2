#ifndef VDSPROJECT_REACHABILITY_TESTS_H
#define VDSPROJECT_REACHABILITY_TESTS_H

#include <gtest/gtest.h>
#include "Reachability.h"
#include "../Manager.h"

using namespace ClassProject;

struct ReachabilityTest : testing::Test
{

    std::unique_ptr<ClassProject::ReachabilityInterface> fsm2 = std::make_unique<ClassProject::Reachability>(2, 2);

    std::vector<BDD_ID> stateVars2 = fsm2->getStates();
    std::vector<BDD_ID> inputVars2 = fsm2->getInputs();
    std::vector<BDD_ID> transitionFunctions;
};


//=======================Runtime error tests=========================

TEST_F(ReachabilityTest, ConstructorRuntimeErrorTest) {
    // throws std::runtime_error if stateSize is zero
    EXPECT_THROW(std::make_unique<ClassProject::Reachability>(0, 0), std::runtime_error);
    EXPECT_THROW(std::make_unique<ClassProject::Reachability>(0, 1), std::runtime_error);
}

TEST_F(ReachabilityTest, isReachableRuntimeErrorTest) {

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);
    // throws std::runtime_error if size does not match with number of state bits
    transitionFunctions.push_back(s0); 
    transitionFunctions.push_back(s1);
    fsm2->setTransitionFunctions(transitionFunctions);
    fsm2->setInitState({false, false});

    // test for one missing state
    EXPECT_THROW(fsm2->isReachable({false}), std::runtime_error);
    // test for one additional state
    EXPECT_THROW(fsm2->isReachable({false, false, false}), std::runtime_error);
}

TEST_F(ReachabilityTest, stateDistanceRuntimeErrorTest) {

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);
    // throws std::runtime_error if size does not match with number of state bits
    transitionFunctions.push_back(s0);
    transitionFunctions.push_back(s1);
    fsm2->setTransitionFunctions(transitionFunctions);
    fsm2->setInitState({false, false});
    // test for one missing state
    EXPECT_THROW(fsm2->stateDistance({false}), std::runtime_error);
    // test for one additional state
    EXPECT_THROW(fsm2->stateDistance({false, false, false}), std::runtime_error);
}

TEST_F(ReachabilityTest, TransistionRuntimeErrorTest) {

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);
    // throws std::runtime_error if size does not match the number of state bits
    transitionFunctions.push_back(s0);
    EXPECT_THROW(fsm2->setTransitionFunctions(transitionFunctions), std::runtime_error);
    // test invalid BDD_ID
    transitionFunctions.push_back((BDD_ID) 9999);
    EXPECT_THROW(fsm2->setTransitionFunctions(transitionFunctions), std::runtime_error);
    transitionFunctions.pop_back();

    // test for one additional transition function
    transitionFunctions.push_back(s1);
    transitionFunctions.push_back(s1);
    EXPECT_THROW(fsm2->setTransitionFunctions(transitionFunctions), std::runtime_error);
}

TEST_F(ReachabilityTest, setInitialStateRuntimeErrorTest){

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);
    // throws std::runtime_error if size does not match with number of state bits
    transitionFunctions.push_back(s0);
    transitionFunctions.push_back(s1);
    fsm2->setTransitionFunctions(transitionFunctions);

    // test for one missing initial state
    EXPECT_THROW(fsm2->setInitState({false}), std::runtime_error);
    // test for one additional initial state
    EXPECT_THROW(fsm2->setInitState({false, false, false}), std::runtime_error);
}

//=========================Reachability tests=========================

TEST_F(ReachabilityTest, HowTo_Example)
{

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->neg(s0));
    transitionFunctions.push_back(fsm2->neg(s1));
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false, false});

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_FALSE(fsm2->isReachable({false, true}));
    ASSERT_FALSE(fsm2->isReachable({true, false}));
    ASSERT_TRUE(fsm2->isReachable({true, true}));
}

TEST_F(ReachabilityTest, HowTo_Example2)
{

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);
    BDD_ID i0 = inputVars2.at(0);
    BDD_ID i1 = inputVars2.at(1);

    transitionFunctions.push_back(fsm2->or2(fsm2->neg(s0), i0)); // s0' = not(s0)+i0
    transitionFunctions.push_back(fsm2->neg(s1));                // s1' = not(s1) 1 0
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false, false});

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_TRUE(fsm2->isReachable({false, true}));
    ASSERT_TRUE(fsm2->isReachable({true, false}));
    ASSERT_TRUE(fsm2->isReachable({true, true}));
}

TEST_F(ReachabilityTest, HowTo_Example3)
{

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->xor2(s0, s1)); // s0' = s0 ^ s1
    transitionFunctions.push_back(fsm2->neg(s1));      // s1' = not(s1)
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false, false});

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_TRUE(fsm2->isReachable({false, true}));
    ASSERT_TRUE(fsm2->isReachable({true, false}));
    ASSERT_TRUE(fsm2->isReachable({true, true}));
}

TEST_F(ReachabilityTest, HowTo_Example4)
{

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->neg(s0));
    transitionFunctions.push_back(fsm2->neg(s1));
    //fsm2->setTransitionFunctions(transitionFunctions);

    //fsm2->setInitState({false, false});

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_FALSE(fsm2->isReachable({false, true}));
    ASSERT_FALSE(fsm2->isReachable({true, false}));
    ASSERT_FALSE(fsm2->isReachable({true, true}));
}
//=========================Reachability with inputs tests=========================

struct InputReachabilityTest : testing::Test
{
    std::unique_ptr<ClassProject::ReachabilityInterface> fsm = std::make_unique<ClassProject::Reachability>(2, 1);

    std::vector<BDD_ID> stateVars = fsm->getStates();
    std::vector<BDD_ID> inputVars = fsm->getInputs();
    std::vector<BDD_ID> transitionFunctions;

    BDD_ID s0 = stateVars[0];
    BDD_ID s1 = stateVars[1];
    BDD_ID i0 = inputVars[0];
};

TEST_F(InputReachabilityTest, InputTest)
{

    transitionFunctions.push_back(fsm->and2(s0, i0));
    transitionFunctions.push_back(true);
    fsm->setTransitionFunctions(transitionFunctions);
    // start from state 01
    fsm->setInitState({false, true});
    EXPECT_FALSE(fsm->isReachable({false, false}));
}
TEST_F(InputReachabilityTest, InputTest2)
{

    transitionFunctions.push_back(fsm->and2(s0, i0));
    transitionFunctions.push_back(true);
    fsm->setTransitionFunctions(transitionFunctions);
    // start from state 00
    fsm->setInitState({false, false});
    EXPECT_TRUE(fsm->isReachable({false, true}));
    EXPECT_TRUE(fsm->isReachable({false, false}));
    EXPECT_FALSE(fsm->isReachable({true, false}));
    EXPECT_FALSE(fsm->isReachable({true, true}));
}

//=========================State distance tests=========================

struct distanceReachabilityTest : testing::Test
{

    std::unique_ptr<ClassProject::ReachabilityInterface> fsm2 = std::make_unique<ClassProject::Reachability>(2, 1);
    std::unique_ptr<ClassProject::ReachabilityInterface> fsm3 = std::make_unique<ClassProject::Reachability>(3);

    std::vector<BDD_ID> stateVars2 = fsm2->getStates();
    std::vector<BDD_ID> inputVars = fsm2->getInputs();
    std::vector<BDD_ID> stateVars3 = fsm3->getStates();
    std::vector<BDD_ID> transitionFunctions;
};

TEST_F(distanceReachabilityTest, distance1)
{

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->neg(s0));
    transitionFunctions.push_back(fsm2->neg(s1));
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false, false});

    EXPECT_EQ(fsm2->stateDistance({false, false}), 0);
    EXPECT_EQ(fsm2->stateDistance({true, true}), 1);
    EXPECT_EQ(fsm2->stateDistance({true, false}), -1);
    EXPECT_EQ(fsm2->stateDistance({false, true}), -1);
}

TEST_F(distanceReachabilityTest, distance2)
{
    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->neg(s1));
    transitionFunctions.push_back(s0);
    fsm2->setTransitionFunctions(transitionFunctions);
    
    fsm2->setInitState({false, false});

    EXPECT_EQ(fsm2->stateDistance({false, false}), 0);
    EXPECT_EQ(fsm2->stateDistance({true, false}), 1);
    EXPECT_EQ(fsm2->stateDistance({true, true}), 2);
    EXPECT_EQ(fsm2->stateDistance({false, true}), 3);
}

TEST_F(distanceReachabilityTest, distance3)
{

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);
    BDD_ID i0 = inputVars.at(0);

    transitionFunctions.push_back(fsm2->or2(fsm2->neg(s0), i0)); // s0' = not(s0)+i0
    transitionFunctions.push_back(fsm2->neg(s1));                // s1' = not(s1) 1 0
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false, false});

    EXPECT_EQ(fsm2->stateDistance({false, false}), 0);
    EXPECT_EQ(fsm2->stateDistance({true, true}), 1);
    EXPECT_EQ(fsm2->stateDistance({true, false}), 2);
    EXPECT_EQ(fsm2->stateDistance({false, true}), 3);
}

TEST_F(distanceReachabilityTest, distance4)
{

    BDD_ID s0 = stateVars2.at(0);
    BDD_ID s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->xor2(s0, s1));
    transitionFunctions.push_back(fsm2->neg(s1));
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false, false});

    EXPECT_EQ(fsm2->stateDistance({false, false}), 0);
    EXPECT_EQ(fsm2->stateDistance({false, true}), 1);
    EXPECT_EQ(fsm2->stateDistance({true, false}), 2);
    EXPECT_EQ(fsm2->stateDistance({true, true}), 3);
}

TEST_F(distanceReachabilityTest, distance5)
{

    BDD_ID s0 = stateVars3.at(0);
    BDD_ID s1 = stateVars3.at(1);
    BDD_ID s2 = stateVars3.at(2);

    transitionFunctions.push_back(fsm3->or2(fsm3->and2(s0, fsm3->nand2(s1, s2)), fsm3->and2(s1, s2)));
    transitionFunctions.push_back(fsm3->xor2(s1, s2));
    transitionFunctions.push_back(fsm3->neg(s2));
    fsm3->setTransitionFunctions(transitionFunctions);

    fsm3->setInitState({false, false, false});

    EXPECT_EQ(fsm3->stateDistance({false, false, false}), 0);
    EXPECT_EQ(fsm3->stateDistance({false, false, true}), 1);
    EXPECT_EQ(fsm3->stateDistance({false, true, false}), 2);
    EXPECT_EQ(fsm3->stateDistance({false, true, true}), 3);
    EXPECT_EQ(fsm3->stateDistance({true, false, false}), 4);
    EXPECT_EQ(fsm3->stateDistance({true, false, true}), 5);
    EXPECT_EQ(fsm3->stateDistance({true, true, false}), 6);
    EXPECT_EQ(fsm3->stateDistance({true, true, true}), 7);
}

TEST(Group2_Test, distanceExample) { /* NOLINT */

    std::unique_ptr<ClassProject::Reachability> distanceFSM = std::make_unique<ClassProject::Reachability>(2,1);
    std::vector<BDD_ID> stateVars6 = distanceFSM->getStates();
    std::vector<BDD_ID> transitionFunctions;

    auto s0 = stateVars6.at(0);
    auto s1 = stateVars6.at(1);
    auto inputs = distanceFSM->getInputs();
    auto i = inputs.at(0);

    auto nots1 = distanceFSM->neg(s1);
    auto nots0 = distanceFSM->neg(s0);
    auto noti = distanceFSM->neg(i);

    //s0' = not(s1)*not(s0)*not(i) + !s1*s0*!i + s1*!s0*!i
    auto s0trans = distanceFSM->or2(distanceFSM->or2(distanceFSM->and2(distanceFSM->and2(nots1, nots0), noti), distanceFSM->and2(distanceFSM->and2(nots1, s0), noti)), distanceFSM->and2(distanceFSM->and2(s1, nots0), noti));
    //s1' = !s1*!s0 + s1*!s0*i + s1s0i
    auto s1trans = distanceFSM->or2(distanceFSM->or2(distanceFSM->and2(nots1, nots0), distanceFSM->and2(distanceFSM->and2(s1, nots0), i)), distanceFSM->and2(distanceFSM->and2(s1, s0), i));

    transitionFunctions.push_back(s0trans);
    transitionFunctions.push_back(s1trans);
    //s1' = not(s3) and (s3 or (s3 nand (s0 and s1)))
    distanceFSM->setTransitionFunctions(transitionFunctions);
    /*
     * Reset state A {false, false}
     * B {false, true}
     * C {true, false}
     * D {true, true}
     * input i
     *
     * A, i = 1 -> B
     * A, i = 0 -> D
     * B, i = 1 -> B
     * B, i = 0 -> C
     * C, i = 1 -> A
     * C, i = 0 -> C
     * D, i = 1 -> B
     * D, i = 0 -> A
     */

    distanceFSM->setInitState({false,false});
    ASSERT_TRUE (distanceFSM->isReachable({true, false}));
    ASSERT_TRUE (distanceFSM->isReachable({false,  true}));
    ASSERT_TRUE (distanceFSM->isReachable({true, true}));
    ASSERT_TRUE (distanceFSM->isReachable({false, false}));

    ASSERT_EQ (distanceFSM->stateDistance({false, false}), 0);
    ASSERT_EQ (distanceFSM->stateDistance({false, true}), 1);
    ASSERT_EQ (distanceFSM->stateDistance({true, true}), 1);
    ASSERT_EQ (distanceFSM->stateDistance({true, false}), 2);

    distanceFSM->setInitState({false,true});
    ASSERT_TRUE (distanceFSM->isReachable({true, false}));
    ASSERT_TRUE (distanceFSM->isReachable({false,  true}));
    ASSERT_TRUE (distanceFSM->isReachable({true, true}));
    ASSERT_TRUE (distanceFSM->isReachable({false, false}));

    ASSERT_EQ (distanceFSM->stateDistance({false, false}), 2);
    ASSERT_EQ (distanceFSM->stateDistance({false, true}), 0);
    ASSERT_EQ (distanceFSM->stateDistance({true, true}), 3);
    ASSERT_EQ (distanceFSM->stateDistance({true, false}), 1);


    distanceFSM->setInitState({true,false});
    ASSERT_TRUE (distanceFSM->isReachable({true, false}));
    ASSERT_TRUE (distanceFSM->isReachable({false,  true}));
    ASSERT_TRUE (distanceFSM->isReachable({true, true}));
    ASSERT_TRUE (distanceFSM->isReachable({false, false}));

    ASSERT_EQ (distanceFSM->stateDistance({false, false}), 1);
    ASSERT_EQ (distanceFSM->stateDistance({false, true}), 2);
    ASSERT_EQ (distanceFSM->stateDistance({true, true}), 2);
    ASSERT_EQ (distanceFSM->stateDistance({true, false}), 0);

    distanceFSM->setInitState({true,true});
    ASSERT_TRUE (distanceFSM->isReachable({true, false}));
    ASSERT_TRUE (distanceFSM->isReachable({false,  true}));
    ASSERT_TRUE (distanceFSM->isReachable({true, true}));
    ASSERT_TRUE (distanceFSM->isReachable({false, false}));

    ASSERT_EQ (distanceFSM->stateDistance({false, false}), 1);
    ASSERT_EQ (distanceFSM->stateDistance({false, true}), 1);
    ASSERT_EQ (distanceFSM->stateDistance({true, true}), 0);
    ASSERT_EQ (distanceFSM->stateDistance({true, false}), 2);

}



#endif
