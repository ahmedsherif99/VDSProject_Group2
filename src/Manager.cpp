#include "Manager.h"
#include <iostream>


using namespace std;

using namespace ClassProject;

Manager::Manager() {
    unique_table_attr false_row = {1,0,0,0,"False"};
    unique_table_attr true_row = {2,0,0,0,"True"};
    unique_table.push_back(false_row);
    unique_table.push_back(true_row);
    cout << "Constructor Instantiated" <<endl;
}

BDD_ID Manager::createVar(const std::string &label) {
    unique_table_attr new_variable = {(unique_table.size()+1),(unique_table.size()+1),1,2,label};
    unique_table.push_back(new_variable);
    return unique_table[unique_table.size()-1].id;
}
const BDD_ID&  Manager::False() {
    return unique_table[0].id;
}
const BDD_ID & Manager::True(){
    return unique_table[1].id;
}