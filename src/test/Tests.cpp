//
// Created by enano on 11/27/2023.
//

#include "Tests.h"

using namespace ClassProject;
TEST(Test, Test){
    ClassProject::Manager FirstTest;
    EXPECT_EQ(FirstTest.getTable().size,2);
}
