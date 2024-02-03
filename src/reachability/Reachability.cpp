#include "Reachability.h"
#include <iostream>
#include <fstream>


using namespace std;

using namespace ClassProject;


Reachability::Reachability(unsigned int stateSize, unsigned int inputSize) {
    //ClassProject::Manager manager;
    while(stateSize > 0){
        //stateVars.push_back(manager.createVar("s" + to_string(stateSize)));
        stateSize--;
    }
    cout << "Constructor Instantiated" << endl;
}
