
#include "Tests.h"

using namespace ClassProject;

TEST(Interfacefunctionstests, Managerinit_funcTest){
    Manager constructorTest;
    EXPECT_EQ(constructorTest.False(),0);
    EXPECT_EQ(constructorTest.True(),1);
}

TEST(Interfacefunctionstests, createvar_functest ){
    Manager createvarTest;
    BDD_ID a = createvarTest.createVar("a");
    EXPECT_EQ(a,2);
}
TEST(Interfacefunctionstests, false_functest ){
    Manager false_test;
    EXPECT_EQ(false_test.False(),0);
}
TEST(Interfacefunctionstests, true_functest ){
    Manager true_test;
    EXPECT_EQ(true_test.True(),1);
}
TEST(Interfacefunctionstests, constant_functest ){
    Manager constant_test;
    BDD_ID a = constant_test.createVar("a");
    EXPECT_EQ(constant_test.isConstant(constant_test.True()),true);
    EXPECT_EQ(constant_test.isConstant(constant_test.False()),true);
    EXPECT_EQ(constant_test.isConstant(a),false);
}
TEST(Interfacefunctionstests, variable_functiontest){
    Manager variable_test;
    BDD_ID a = variable_test.createVar("a");
    EXPECT_EQ(variable_test.isVariable(variable_test.True()),false);
    EXPECT_EQ(variable_test.isVariable(variable_test.False()),false);
    EXPECT_EQ(variable_test.isVariable(a),true);
}
TEST(Interfacefunctionstests, topvariabletest){
    Manager topvar_test;
    BDD_ID a = topvar_test.createVar("a");
    EXPECT_EQ(topvar_test.topVar(a),a);
}