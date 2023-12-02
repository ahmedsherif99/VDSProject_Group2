// A minimalistic BDD library, following Wolfgang Kunz lecture slides
//
// Created by Markus Wedler 2014

#ifndef VDSPROJECT_MANAGER_H
#define VDSPROJECT_MANAGER_H

#include "ManagerInterface.h"
#include <vector>

namespace ClassProject {

    class Manager : public ManagerInterface {
        struct unique_table_attr {
            BDD_ID id;
            BDD_ID topvariable;
            BDD_ID low;
            BDD_ID high;
            std:: string label;
        };
    private:
        std:: vector <unique_table_attr> unique_table;
    public:
        Manager();
        BDD_ID createVar(const std::string &label) override;
        const BDD_ID &True() override;
        const BDD_ID &False() override;
    };

}


#endif
