
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
TEST(Interfacefunctionstests, constant_functest ){
    Manager constant_test;
    BDD_ID a = constant_test.createVar("a");
    EXPECT_EQ(constant_test.isConstant(constant_test.True()),true);
    EXPECT_EQ(constant_test.isConstant(constant_test.False()),true);
    EXPECT_EQ(constant_test.isConstant(a),false);
}