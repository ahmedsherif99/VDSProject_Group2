//
// Created by Carolina P. Nogueira 2016
//

#include <iostream>
#include <string>
#include "Manager.h"


int main(int argc, char *argv[]) {
    ClassProject::Manager manager;

    auto a = manager.createVar("a");
    auto b = manager.createVar("b");
    auto c = manager.createVar("c");
    auto d = manager.createVar("d");

    auto f = manager.and2(manager.or2(a, b), manager.and2(c, d));

    manager.visualizeBDD("ROBDD.dot", f);
}
