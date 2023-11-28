#include "Manager.h"
#include <iostream>

using namespace ClassProject;

    Manager::Manager() {
        std::cout << "Instantiated";
    }

    BDD_ID Manager::createVar(const std::string &label) {
        BDD_ID test = 3;
        return test;
    }