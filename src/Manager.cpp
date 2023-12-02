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
    }
    const BDD_ID&  Manager::False() {
    }
const BDD_ID & Manager::True(){
}