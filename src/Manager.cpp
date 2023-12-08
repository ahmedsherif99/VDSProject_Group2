#include "Manager.h"
#include <iostream>


using namespace std;

using namespace ClassProject;

Manager::Manager() {
    unique_table_attr false_row = {0,0,0,0,"False"};
    unique_table_attr true_row = {1,1,1,1,"True"};
    unique_table.push_back(false_row);
    unique_table.push_back(true_row);
    cout << "Constructor Instantiated" <<endl;
}

BDD_ID Manager::createVar(const std::string &label) {
    unique_table_attr new_variable = {(unique_table.size()),(unique_table.size()),0,1,label};
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
    else if(t == unique_table[0].id && e == unique_table[1].id){
        //return neg(i); find a way to implement this
    }

    // check if it precomputed before
    auto search_result = computed_table.find({i,t,e});
    if(search_result != computed_table.end()){
        return search_result->second;
    }

    // compute the ite value
    // find the top variable for ite
    vector <BDD_ID>topvariable = {topVar(i), topVar(t), topVar(e)};

    /*topvariable.erase(remove_if(topvariable.begin(), topvariable.end(), [this](BDD_ID var) { return isConstant(var); }), topvariable.end());
    sort(topvariable.begin(),topvariable.end());
    auto found_topvariable = unique_table[topvariable.front()];*/

    auto min_topvar= topVar(i)+ topVar(t)+ topVar(e);
    for (int number=0; number<3;number++){
        if(!isConstant(topvariable[number])){
            if(topvariable[number]<min_topvar){
                min_topvar = topvariable[number];
            }
        }
    }
    auto rhigh = ite(coFactorTrue(i,unique_table[min_topvar].id),coFactorTrue(t,unique_table[min_topvar].id),coFactorTrue(e,unique_table[min_topvar].id));
    auto rlow = ite(coFactorFalse(i,unique_table[min_topvar].id),coFactorFalse(t,unique_table[min_topvar].id),coFactorFalse(e,unique_table[min_topvar].id));
    //possible reduction
    if (rhigh==rlow){
        return rhigh;
    }
    // remove isomorphic graphs

    //find or add to the unique table
   auto search_r = find(unique_table.begin(),unique_table.end());
}

BDD_ID Manager::coFactorTrue(BDD_ID f, BDD_ID x){

}
BDD_ID Manager::coFactorFalse(BDD_ID f, BDD_ID x){

}
BDD_ID Manager::coFactorTrue(BDD_ID f) {

}
BDD_ID Manager::coFactorFalse(BDD_ID f) {

}

size_t Manager::uniqueTableSize(){
    return unique_table.size();
}

