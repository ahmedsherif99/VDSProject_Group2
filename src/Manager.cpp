#include "Manager.h"
#include <iostream>
#include <fstream>


using namespace std;

using namespace ClassProject;

Manager::Manager() {
    unique_table_attr false_row = {0, 0, 0, 0, "False"};
    unique_table_attr true_row = {1, 1, 1, 1, "True"};
    key false_key = {0, 0, 0};
    key true_key = {1, 1, 1};
    unique_table.push_back(false_row);
    unique_table.push_back(true_row);
    unique_table_search.emplace(false_key, unique_table[0].id);
    unique_table_search.emplace(true_key, unique_table[1].id);
    cout << "Constructor Instantiated" << endl;
}

BDD_ID Manager::createVar(const std::string &label) {
    unique_table_attr new_variable = {(unique_table.size()), (unique_table.size()), 0, 1, label};
    key variable_key = {unique_table.size(), 0, 1};
    unique_table_search.emplace(variable_key, unique_table.size());
    unique_table.push_back(new_variable);
    return unique_table[unique_table.size() - 1].id;
}

const BDD_ID &Manager::False() {
    return unique_table[0].id;
}

const BDD_ID &Manager::True() {
    return unique_table[1].id;
}

bool Manager::isConstant(BDD_ID f) {
    if (f == Manager::False() || f == Manager::True()) {
        return true;
    } else {
        return false;
    }
}

bool Manager::isVariable(BDD_ID x) {
    if (unique_table[x].high == Manager::True() && unique_table[x].low == Manager::False()) {
        return true;
    } else {
        return false;
    }
}

BDD_ID Manager::topVar(BDD_ID f) {
    return unique_table[f].topvariable;
}

BDD_ID Manager::ite(BDD_ID i, BDD_ID t, BDD_ID e) {
    // Terminal cases
    if (i == Manager::True()) { //this is the true node
        return t;
    } else if (i == Manager::False()) { //this is the false node
        return e;
    } else if (t == Manager::True() && e == Manager::False()) {
        return i;
    } else if (t == e) {
        return t;
    }

    // check if it precomputed before
    auto search_result = computed_table.find({i, t, e});
    if (search_result != computed_table.end()) {
        return search_result->second;
    }

    // compute the ite value
    // find the top variable for ite
    vector<BDD_ID> topvariable = {topVar(i), topVar(t), topVar(e)};
    auto min_topvar = topVar(i) + topVar(t) + topVar(e);
    for (int number = 0; number < 3; number++) {
        if (!isConstant(topvariable[number])) {
            if (topvariable[number] < min_topvar) {
                min_topvar = topvariable[number];
            }
        }
    }
    auto rhigh = ite(coFactorTrue(i, unique_table[min_topvar].id), coFactorTrue(t, unique_table[min_topvar].id),
                     coFactorTrue(e, unique_table[min_topvar].id));
    auto rlow = ite(coFactorFalse(i, unique_table[min_topvar].id), coFactorFalse(t, unique_table[min_topvar].id),
                    coFactorFalse(e, unique_table[min_topvar].id));
    //possible reduction
    if (rhigh == rlow) {
        return rhigh;
    }

    // remove isomorphic graphs
    auto search_r = unique_table_search.find({unique_table[min_topvar].id, rlow, rhigh});
    if (search_r != unique_table_search.end()) {
        return search_r->second;
    }
    string new_label = to_string(unique_table.size());
    /*if (e==0){
        new_label = to_string(i) + " and " + to_string(t);
    }else if (t==1){
        new_label = to_string(i) + " or " + to_string(e);
    }else if (e==1){
        new_label = to_string(i) + " xor " + to_string(t);
    }else if (t==0){
        new_label = to_string(i) + " xnor " + to_string(e);
    }*/
    /*
        if (e==0){
        new_label = "(" + unique_table[i].label + " . " + unique_table[t].label + ")";
    }else if (t==1){
        new_label = "(" + unique_table[i].label + " + " + unique_table[e].label+ ")";
    }else if (e==1){
        new_label = "(" + unique_table[i].label + " ^ " + unique_table[t].label+ ")";
    }else if (t==0){
        new_label = "(" + unique_table[i].label + " xnor " + unique_table[e].label + ")";
    }
    */
    unique_table_attr new_node = {unique_table.size(), min_topvar, rlow, rhigh, new_label};
    key new_node_key = {unique_table[min_topvar].id, rlow, rhigh};
    unique_table_search.emplace(new_node_key, new_node.id);
    computed_table.insert({{i, t, e}, new_node.id});
    unique_table.push_back(new_node);
    return unique_table[unique_table.size() - 1].id;
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

BDD_ID Manager::coFactorFalse(BDD_ID f, BDD_ID x) {
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
    if (isConstant(f)) {
        return f;
    } else {
        return unique_table[f].high;
    }
}

BDD_ID Manager::coFactorFalse(BDD_ID f) {
    if (isConstant(f)) {
        return f;
    } else {
        return unique_table[f].low;
    }
}

size_t Manager::uniqueTableSize() {
    return unique_table.size();
}

BDD_ID Manager::and2(BDD_ID a, BDD_ID b) {
    return ite(a, b, 0);
}

BDD_ID Manager::or2(BDD_ID a, BDD_ID b) {
    return ite(a, 1, b);
}

BDD_ID Manager::xor2(BDD_ID a, BDD_ID b) {
    return ite(a, neg(b), b);
}

BDD_ID Manager::neg(BDD_ID a) {
    return ite(a, 0, 1);
}

BDD_ID Manager::nand2(BDD_ID a, BDD_ID b) {
    return neg(and2(a, b));
}

BDD_ID Manager::nor2(BDD_ID a, BDD_ID b) {
    return neg(or2(a, b));
}

BDD_ID Manager::xnor2(BDD_ID a, BDD_ID b) {
    return neg(xor2(a, b));
}

std::string Manager::getTopVarName(const BDD_ID &root) {
    auto topvarname = topVar(root);
    return unique_table[topvarname].label;
}

void Manager::findNodes(const BDD_ID &root, std::set<BDD_ID> &nodes_of_root) {
    nodes_of_root.insert(root);
    if (isConstant(root)) {
        return;
    }
    findNodes(coFactorTrue(root), nodes_of_root);
    findNodes(coFactorFalse(root), nodes_of_root);
}

void Manager::findVars(const BDD_ID &root, std::set<BDD_ID> &vars_of_root) {
    if (isConstant(root)) {
        return;
    }
    vars_of_root.insert(topVar(root));
    findVars(coFactorTrue(root), vars_of_root);
    findVars(coFactorFalse(root), vars_of_root);
}

void Manager::visualizeBDD(std::string filepath, BDD_ID &root) {
    std::ofstream file(filepath);
    file << "strict digraph A {\n";
    file << "graph [bgcolor=white]\n";
    file << "node [fillcolor=white, fontname=Arial]\n";
    visualizeBDDrecursive(file, root);
    file << "}\n";
}

void Manager::visualizeBDDrecursive(std::ofstream &file, BDD_ID &root) {
    auto &node = unique_table[root];

    file << node.id << " [label=\"" << node.label << "\"]\n";
    if (isConstant(root)) return;

    visualizeBDDrecursive(file, node.low);
    file << node.id << " -> " << node.low << " [style=dotted]\n";

    visualizeBDDrecursive(file, node.high);
    file << node.id << " ->" << node.high << " [style=solid]\n";
}
