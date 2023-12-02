
#include "Tests.h"

using namespace ClassProject;

TEST(Interfacefunctionstests, Managerinit_funcTest){
    Manager constructorTest;
    EXPECT_EQ(constructorTest.False(),1);
    EXPECT_EQ(constructorTest.True(),2);
}

TEST(Interfacefunctionstests, createvar_functest ){
    Manager createvarTest;
    BDD_ID a = createvarTest.createVar("a");
    EXPECT_EQ(a,3);

}
TEST(Interfacefunctionstests, false_functest ){
    Manager false_test;
    EXPECT_EQ(false_test.False(),1);

}
TEST(Interfacefunctionstests, true_functest ){
    Manager true_test;
    EXPECT_EQ(true_test.True(),2);

}