// A minimalistic BDD library, following Wolfgang Kunz lecture slides
//
// Created by Markus Wedler 2014

#ifndef VDSPROJECT_MANAGER_H
#define VDSPROJECT_MANAGER_H

#include "ManagerInterface.h"
#include <vector>
#include <map>
#include <boost/functional/hash.hpp>
#include <algorithm>

namespace ClassProject {

    class Manager : public ManagerInterface {
        struct unique_table_attr {
            BDD_ID id;
            BDD_ID topvariable;
            BDD_ID low;
            BDD_ID high;
            std:: string label;
        };
        struct key {
            BDD_ID first;
            BDD_ID second;
            BDD_ID third;
            bool operator==(const key &compared) const
            { return (first==compared.first && second==compared.second && third==compared.third);
            }
        };
        struct keyhasherstruct { //custom hash struct function for the unordered_map hash calculation for the struct key
            std::size_t operator()(const key& k) const {
                std::size_t hashX = std::hash<BDD_ID>{}(k.first);
                std::size_t hashY = std::hash<BDD_ID>{}(k.second);
                std::size_t hashZ = std::hash<BDD_ID>{}(k.third);
                size_t result = hashX ^ (hashY << 1) ^ (hashZ << 2);
                // Combining hash values using XOR and left shifts
                return result;
            }
        };
    private:
        std:: vector <unique_table_attr> unique_table;
        std:: unordered_map <key,BDD_ID,keyhasherstruct> computed_table;
        std:: unordered_map <key,BDD_ID,keyhasherstruct> unique_table_search;
    public:
        Manager();
        BDD_ID createVar(const std::string &label) override;
        const BDD_ID &True() override;
        const BDD_ID &False() override;
        bool isConstant(BDD_ID f) override;
        bool isVariable(BDD_ID x) override;
        BDD_ID topVar(BDD_ID f) override;
        BDD_ID ite(BDD_ID i, BDD_ID t, BDD_ID e) override;
        BDD_ID coFactorTrue(BDD_ID f, BDD_ID x) override;
        BDD_ID coFactorFalse(BDD_ID f, BDD_ID x) override;
        BDD_ID coFactorTrue(BDD_ID f) override;
        BDD_ID coFactorFalse(BDD_ID f) override;
        BDD_ID and2(BDD_ID a, BDD_ID b) override;
        BDD_ID or2(BDD_ID a, BDD_ID b) override;
        BDD_ID xor2(BDD_ID a, BDD_ID b) override;
        BDD_ID neg(BDD_ID a) override;
        BDD_ID nand2(BDD_ID a, BDD_ID b) override;
        BDD_ID nor2(BDD_ID a, BDD_ID b) override;
        BDD_ID xnor2(BDD_ID a, BDD_ID b) override;
        size_t uniqueTableSize() override;
        std::string getTopVarName(const BDD_ID &root) override;
        void findNodes(const BDD_ID &root, std::set<BDD_ID> &nodes_of_root) override;
        void findVars(const BDD_ID &root, std::set<BDD_ID> &vars_of_root) override;


    };

}


#endif
