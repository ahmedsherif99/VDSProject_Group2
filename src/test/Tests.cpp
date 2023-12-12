
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
    set <BDD_ID> node_set1;
    set <BDD_ID> node_set2;
    set <BDD_ID> node_set3;
    test_var->findNodes(a,node_set1);
    EXPECT_EQ(node_set1.size(),3);
    test_var->findNodes(x,node_set2);
    EXPECT_EQ(node_set2.size(),4);
    test_var->findNodes(y,node_set3);
    EXPECT_EQ(node_set3.size(),4);
}
TEST_F(Manager_test,findvariablestest){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    BDD_ID x = test_var->and2(a,b);
    BDD_ID y = test_var->or2(a,b);
    set <BDD_ID> node_set1;
    set <BDD_ID> node_set2;
    set <BDD_ID> node_set3;
    test_var->findVars(a,node_set1);
    EXPECT_EQ(node_set1.size(),1);
    test_var->findVars(x,node_set2);
    EXPECT_EQ(node_set2.size(),2);
    test_var->findVars(y,node_set3);
    EXPECT_EQ(node_set3.size(),2);
}


TEST_F(Manager_test,restofCoveragetest){
    //this test is to cover the cases of having a value in the pre computed table
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    BDD_ID x = test_var->and2(a,b);
    BDD_ID y = test_var->and2(a,b);
    BDD_ID z = test_var->ite(a,1,test_var->neg(a));
    EXPECT_EQ(test_var->topVar(x),a);
    EXPECT_EQ(test_var->coFactorTrue(x),b); // rhigh of a.b is b
    EXPECT_EQ(test_var->coFactorFalse(x),0); // rlow of a.b is 0
    EXPECT_EQ(test_var->topVar(y),a);
    EXPECT_EQ(y,x);
    EXPECT_EQ(test_var->coFactorTrue(y),b); // rhigh of a.b is b
    EXPECT_EQ(test_var->coFactorFalse(y),0); // rlow of a.b is 0
    EXPECT_EQ(test_var->topVar(z),1);
    EXPECT_EQ(test_var->coFactorTrue(z),1); // rhigh of a.b is b
    EXPECT_EQ(test_var->coFactorFalse(z),1); // rlow of a.b is 0

}

TEST_F(Manager_test, Finaltest){
    BDD_ID a = test_var->createVar("a");
    BDD_ID b = test_var->createVar("b");
    BDD_ID c = test_var->createVar("c");
    BDD_ID d = test_var->createVar("d");
    EXPECT_EQ(test_var->uniqueTableSize(),6);
    auto a_or_b = test_var->or2(a,b);
    EXPECT_EQ(test_var->topVar(a_or_b),a);
    EXPECT_EQ(test_var->coFactorTrue(a_or_b),1); // rhigh of a+b is 1
    EXPECT_EQ(test_var->coFactorFalse(a_or_b),b); // rlow of a+b is b
    EXPECT_EQ(test_var->uniqueTableSize(),7);
    auto c_and_d = test_var->and2(c,d);
    EXPECT_EQ(test_var->topVar(c_and_d),c);
    EXPECT_EQ(test_var->coFactorTrue(c_and_d),d); // rhigh of c.d is d
    EXPECT_EQ(test_var->coFactorFalse(c_and_d),0); // rlow of c.d is 0
    EXPECT_EQ(test_var->uniqueTableSize(),8);
    auto f = test_var->and2(a_or_b,c_and_d);
    EXPECT_EQ(test_var->topVar(f),a);
    EXPECT_EQ(test_var->coFactorTrue(f),c_and_d); // rhigh of c.d is d
    EXPECT_EQ(test_var->coFactorFalse(f),c_and_d+1); // rlow of c.d is 0
    EXPECT_EQ(test_var->uniqueTableSize(),10);
}
