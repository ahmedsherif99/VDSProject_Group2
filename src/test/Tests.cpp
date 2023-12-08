
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
TEST_F(Manager_test,and2test){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    EXPECT_EQ(test_var->topVar(test_var->and2(a,b)),a);
    EXPECT_EQ(test_var->coFactorTrue(test_var->and2(a,b)),b); // rhigh of a.b is b
    EXPECT_EQ(test_var->coFactorFalse(test_var->and2(a,b)),0); // rlow of a.b is 0

}
TEST_F(Manager_test,or2test){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    EXPECT_EQ(test_var->topVar(test_var->or2(a,b)),a);
    EXPECT_EQ(test_var->coFactorTrue(test_var->or2(a,b)),1); // rhigh of a+b is 1
    EXPECT_EQ(test_var->coFactorFalse(test_var->or2(a,b)),b); // rlow of a+b is b

}
TEST_F(Manager_test,xor2test){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    EXPECT_EQ(test_var->topVar(test_var->xor2(a,b)),a);
    EXPECT_EQ(test_var->coFactorTrue(test_var->xor2(a,b)),test_var->neg(b)); // rhigh of a^b is !b
    EXPECT_EQ(test_var->coFactorFalse(test_var->xor2(a,b)),b); // rlow of a^b is b
}
TEST_F(Manager_test,negtest){
    BDD_ID a = test_var->createVar("a");
    EXPECT_EQ(test_var->coFactorTrue(test_var->neg(a)),0); // neg of rhigh is 0
    EXPECT_EQ(test_var->coFactorFalse(test_var->neg(a)),1); // neg of rlow is 1

}
TEST_F(Manager_test,nand2test){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    EXPECT_EQ(test_var->topVar(test_var->nand2(a,b)),a);
    EXPECT_EQ(test_var->coFactorTrue(test_var->nand2(a,b)),test_var->neg(b)); // rhigh of !(a.b) is 1
    EXPECT_EQ(test_var->coFactorFalse(test_var->nand2(a,b)),1); // rlow of !(a.b) is neg(b)

}
TEST_F(Manager_test,nor2test){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    EXPECT_EQ(test_var->topVar(test_var->nor2(a,b)),a);
    EXPECT_EQ(test_var->coFactorTrue(test_var->nor2(a,b)),0); // rhigh of !(a+b) is 0
    EXPECT_EQ(test_var->coFactorFalse(test_var->nor2(a,b)),test_var->neg(b)); // rlow of !(a+b) is neg(b)

}
TEST_F(Manager_test,xnor2test){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    EXPECT_EQ(test_var->topVar(test_var->xnor2(a,b)),a);
    EXPECT_EQ(test_var->coFactorTrue(test_var->xnor2(a,b)),b); // rhigh of a^b is !b
    EXPECT_EQ(test_var->coFactorFalse(test_var->xnor2(a,b)),test_var->neg(b)); // rlow of a^b is b
}
TEST_F(Manager_test,uniquetablesizetest){
    EXPECT_EQ(test_var->uniqueTableSize(),2);
    test_var->createVar("a");
    EXPECT_EQ(test_var->uniqueTableSize(),3);
}
TEST_F(Manager_test,gettopvariablenametest){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    BDD_ID y = test_var->and2(a,b);
    EXPECT_EQ(test_var->getTopVarName(a),"a");
    EXPECT_EQ(test_var->getTopVarName(b),"b");
    EXPECT_EQ(test_var->getTopVarName(y),"a");
}
TEST_F(Manager_test,findnodestest){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    BDD_ID x = test_var->and2(a,b);
    BDD_ID y = test_var->or2(a,b);
    set <BDD_ID> node_set;
    test_var->findNodes(a,node_set);
    EXPECT_EQ(node_set.size(),3);
    test_var->findNodes(x,node_set);
    EXPECT_EQ(node_set.size(),4);
    test_var->findNodes(y,node_set);
    EXPECT_EQ(node_set.size(),4);
}
TEST_F(Manager_test,findvariablestest){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    BDD_ID x = test_var->and2(a,b);
    BDD_ID y = test_var->or2(a,b);
    set <BDD_ID> node_set;
    test_var->findVars(a,node_set);
    EXPECT_EQ(node_set.size(),1);
    test_var->findVars(x,node_set);
    EXPECT_EQ(node_set.size(),2);
    test_var->findVars(y,node_set);
    EXPECT_EQ(node_set.size(),2);
}