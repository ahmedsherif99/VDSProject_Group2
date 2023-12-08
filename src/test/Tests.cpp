
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
    //Test new node
    EXPECT_EQ(test_var->ite(a,b,0),b+1); // new node id after b
    EXPECT_EQ(test_var->ite(a,1,b),b+2); // new node id after b+1
    //EXPECT_EQ(test_var->ite(a,test_var->False(),test_var->True()),a);   expect test_var->neg(a)
}
TEST_F(Manager_test,Cofactortruetest){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    EXPECT_EQ(test_var->coFactorTrue(test_var->True(),test_var->topVar(test_var->True())),test_var->True()); // constant
    EXPECT_EQ(test_var->coFactorTrue(a,test_var->topVar(a)),1); //high of a
    EXPECT_EQ(test_var->coFactorTrue(a,test_var->topVar(b)),a); //a is independent of b
}
TEST_F(Manager_test,Cofactorfalsetest){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    EXPECT_EQ(test_var->coFactorFalse(test_var->False(),test_var->topVar(test_var->False())),test_var->False()); //constant
    EXPECT_EQ(test_var->coFactorFalse(a,test_var->topVar(a)),0); //low of a
    EXPECT_EQ(test_var->coFactorFalse(a,test_var->topVar(b)),a); //a is independent of b
}
TEST_F(Manager_test,Cofactortruewithouttopvartest){
    BDD_ID a = test_var->createVar("a");
    EXPECT_EQ(test_var->coFactorTrue(test_var->True()),test_var->True()); // constant
    EXPECT_EQ(test_var->coFactorTrue(a),1); //high of a
}
TEST_F(Manager_test,Cofactorfalsewithouttopvartest){
    BDD_ID a = test_var->createVar("a");
    EXPECT_EQ(test_var->coFactorFalse(test_var->False()),test_var->False()); //constant
    EXPECT_EQ(test_var->coFactorFalse(a),0); //low of a
}
TEST_F(Manager_test,uniquetablesizetest){
    EXPECT_EQ(test_var->uniqueTableSize(),2);
    test_var->createVar("a");
    EXPECT_EQ(test_var->uniqueTableSize(),3);
}
