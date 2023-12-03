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
size_t Manager::uniqueTableSize(){
    return unique_table.size();
}