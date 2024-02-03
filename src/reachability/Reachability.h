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
        //Reachability(unsigned int , unsigned int );

        //~Reachability(unsigned int stateSize, unsigned int inputSize) = default;

        //const std::vector<BDD_ID> &getStates() override;

        explicit Reachability(unsigned int stateSize, unsigned int inputSize = 0);

        inline const std::vector<BDD_ID> &getStates() const override {
            //return states;
        }

        inline const std::vector<BDD_ID> &getInputs() const override {
            //return inputs;
        }

        bool isReachable(const std::vector<bool> &stateVector) override;
        int stateDistance(const std::vector<bool> &stateVector) override;
        void setTransitionFunctions(
            const std::vector<BDD_ID> &transitionFunctions) override;
        void setInitState(const std::vector<bool> &stateVector) override;

        private:
        BDD_ID existential_quantification(const BDD_ID &f,
                                            const std::vector<BDD_ID> &v);
            };

}
#endif
