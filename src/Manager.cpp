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

    // check if it precomputed before
    auto search_result = computed_table.find({i,t,e});
    if(search_result != computed_table.end()){
        return search_result->second;
    }

    // compute the ite value
    // find the top variable for ite
    vector <BDD_ID>topvariable = {topVar(i), topVar(t), topVar(e)};
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
   auto search_r = unique_table_search.find({unique_table[min_topvar].id,rlow,rhigh});
    if(search_r != computed_table.end()){
        return search_r->second;
    }
    string new_label = "new_node_" + to_string(unique_table.size());
    unique_table_attr new_node = {unique_table.size(),min_topvar,rlow,rhigh,new_label};
    key new_node_key = {unique_table[min_topvar].id,rlow,rhigh};
    unique_table_search.emplace(new_node_key, unique_table.size());
    unique_table.push_back(new_node);
    return unique_table[unique_table.size()-1].id;
}

BDD_ID Manager::coFactorTrue(BDD_ID f, BDD_ID x) {
    if (isConstant(f) || isConstant(x) || topVar(f) > x) {
        return f;
    }
    if (topVar(f) == x) {
        return unique_table[f].high;
    } else {
        auto T = coFactorTrue(unique_table[f].high, x);
        auto F = coFactorTrue(unique_table[f].low, x);
        return ite(topVar(f), T, F);
    }
}
BDD_ID Manager::coFactorFalse(BDD_ID f, BDD_ID x){
    if (isConstant(f) || isConstant(x) || topVar(f) > x) {
        return f;
    }
    if (topVar(f) == x) {
        return unique_table[f].low;
    } else {
        auto T = coFactorFalse(unique_table[f].high, x);
        auto F = coFactorFalse(unique_table[f].low, x);
        return ite(topVar(f), T, F);
    }
}
BDD_ID Manager::coFactorTrue(BDD_ID f) {
    return unique_table[f].high;
    }
BDD_ID Manager::coFactorFalse(BDD_ID f) {
    return unique_table[f].low;
}

size_t Manager::uniqueTableSize(){
    return unique_table.size();
}

BDD_ID Manager::and2(BDD_ID a, BDD_ID b){
    return ite(a,b,0);
}
BDD_ID Manager::or2(BDD_ID a, BDD_ID b){
    return ite(a,1,b);
}
BDD_ID Manager::xor2(BDD_ID a, BDD_ID b) {
    return ite(a,neg(b),b);
}
BDD_ID Manager::neg(BDD_ID a){
    return ite(a,0,1);
}
BDD_ID Manager::nand2(BDD_ID a, BDD_ID b){
    return neg(and2(a,b));
}
BDD_ID Manager::nor2(BDD_ID a, BDD_ID b){
    return neg(or2(a,b));
}
BDD_ID Manager::xnor2(BDD_ID a, BDD_ID b) {
    return neg(xor2(a,b));
}
std::string Manager::getTopVarName(const BDD_ID &root){

}
void Manager::findNodes(const BDD_ID &root, std::set<BDD_ID> &nodes_of_root) {

}
void Manager::findVars(const BDD_ID &root, std::set<BDD_ID> &vars_of_root) {

}
