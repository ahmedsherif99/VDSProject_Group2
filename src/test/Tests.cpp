
#include "Tests.h"

using namespace std;

using namespace ClassProject;

TEST_F(Manager_test, Managerinit_funcTest){
    EXPECT_EQ(test_var->False(),0);
    EXPECT_EQ(test_var->True(),1);
}

TEST_F(Manager_test, createvar_functest ){
    BDD_ID a = test_var->createVar("a");
    EXPECT_EQ(a,2);
}
TEST_F(Manager_test, false_functest ){
    EXPECT_EQ(test_var->False(),0);
}
TEST_F(Manager_test, true_functest ){
    EXPECT_EQ(test_var->True(),1);
}
TEST_F(Manager_test, constant_functest ){
    BDD_ID a = test_var->createVar("a");
    EXPECT_EQ(test_var->isConstant(test_var->True()),true);
    EXPECT_EQ(test_var->isConstant(test_var->False()),true);
    EXPECT_EQ(test_var->isConstant(a),false);
}
TEST_F(Manager_test, variable_functiontest){;
    BDD_ID a = test_var->createVar("a");
    EXPECT_EQ(test_var->isVariable(test_var->True()),false);
    EXPECT_EQ(test_var->isVariable(test_var->False()),false);
    EXPECT_EQ(test_var->isVariable(a),true);
}
TEST_F(Manager_test, topvariabletest){
    BDD_ID a = test_var->createVar("a");
    EXPECT_EQ(test_var->topVar(a),a);
}
TEST_F(Manager_test,itetest){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");

    //Test Terminal Cases
    EXPECT_EQ(test_var->ite(test_var->True(),a,b),a);
    EXPECT_EQ(test_var->ite(test_var->False(),a,b),b);
    EXPECT_EQ(test_var->ite(a,test_var->True(),test_var->False()),a);
    EXPECT_EQ(test_var->ite(a,b,b),b);
    //EXPECT_EQ(test_var->ite(a,test_var->False(),test_var->True()),a);   expect test_var->neg(a)
}
TEST_F(Manager_test,uniquetablesizetest){
    EXPECT_EQ(test_var->uniqueTableSize(),2);
    test_var->createVar("a");
    EXPECT_EQ(test_var->uniqueTableSize(),3);
}
