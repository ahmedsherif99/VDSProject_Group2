#include "Manager.h"
#include <iostream>


using namespace std;

using namespace ClassProject;

Manager::Manager() {
    unique_table_attr false_row = {0,0,0,0,"False"};
    unique_table_attr true_row = {1,1,1,1,"True"};
    key false_key ={0,0,0};
    key true_key={1,1,1};
    unique_table.push_back(false_row);
    unique_table.push_back(true_row);
    unique_table_search.emplace(false_key,unique_table[0].id);
    unique_table_search.emplace(true_key,unique_table[1].id);
    cout << "Constructor Instantiated" <<endl;
}

BDD_ID Manager::createVar(const std::string &label) {
    unique_table_attr new_variable = {(unique_table.size()),(unique_table.size()),0,1,label};
    key variable_key={unique_table.size(),0,1};
    unique_table_search.emplace(variable_key,unique_table.size());
    unique_table.push_back(new_variable);
    return unique_table[unique_table.size()-1].id;
}
const BDD_ID&  Manager::False() {
    return unique_table[0].id;
}
const BDD_ID & Manager::True(){
    return unique_table[1].id;
}

bool Manager::isConstant(BDD_ID f){
    if (f == unique_table[0].id || f == unique_table[1].id) {
        return true;
    }
    else {
        return false;
    }
}
bool Manager::isVariable(BDD_ID x){
    if (unique_table[x].high == 1 && unique_table[x].low == 0) {
        return true;
    }
    else {
        return false;
    }
}
BDD_ID Manager::topVar(BDD_ID f){
    return unique_table[f].topvariable;
}

BDD_ID Manager::ite(BDD_ID i, BDD_ID t, BDD_ID e){
    // Terminal cases
    if (i==unique_table[1].id){ //this is the true node
        return t;
    }
    else if (i==unique_table[0].id){ //this is the false node
        return e;
    }
    else if (t == unique_table[1].id && e == unique_table[0].id){
        return i;
    }
    else if (t==e){
        return t;
    }


}

BDD_ID Manager::coFactorTrue(BDD_ID f, BDD_ID x) {

}
BDD_ID Manager::coFactorFalse(BDD_ID f, BDD_ID x){

}
BDD_ID Manager::coFactorTrue(BDD_ID f) {

    }
BDD_ID Manager::coFactorFalse(BDD_ID f) {

}

size_t Manager::uniqueTableSize(){

}

BDD_ID Manager::and2(BDD_ID a, BDD_ID b){

}
BDD_ID Manager::or2(BDD_ID a, BDD_ID b){

}
BDD_ID Manager::xor2(BDD_ID a, BDD_ID b) {

}
BDD_ID Manager::neg(BDD_ID a){

}
BDD_ID Manager::nand2(BDD_ID a, BDD_ID b){

}
BDD_ID Manager::nor2(BDD_ID a, BDD_ID b){

}
BDD_ID Manager::xnor2(BDD_ID a, BDD_ID b) {

}

