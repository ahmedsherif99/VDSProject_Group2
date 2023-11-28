// A minimalistic BDD library, following Wolfgang Kunz lecture slides
//
// Created by Markus Wedler 2014

#ifndef VDSPROJECT_MANAGER_H
#define VDSPROJECT_MANAGER_H

#include "ManagerInterface.h"

namespace ClassProject {

    class Manager : public ManagerInterface {

    public:
        Manager();
        BDD_ID createVar(const std::string &label) override;
    };

    int table[20];
}


#endif
