#ifndef VDSPROJECT_REACHABILITY_H
#define VDSPROJECT_REACHABILITY_H

#include "../Manager.h"
#include "ReachabilityInterface.h"
#include <vector>

namespace ClassProject {

    class Reachability : public ReachabilityInterface {
    private:
        std::vector<BDD_ID> stateVars;
        std::vector<BDD_ID> inputVars;
        std::vector<BDD_ID> transitionFunctions;
        std::vector<bool> initState;
    public:
        Reachability(unsigned int stateSize, unsigned int inputSize = 0);

        //~Reachability(unsigned int stateSize, unsigned int inputSize) = default;

        //const std::vector<BDD_ID> &getStates() override;

       

}
#endif
