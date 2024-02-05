#include "Reachability.h"
#include <iostream>
#include <fstream>

using namespace std;

using namespace ClassProject;

Reachability::Reachability(unsigned int stateSize, unsigned int inputSize)
{
    for (unsigned int i = 0; i < stateSize; i++)
    {
        stateVars.push_back(0);
    }
    for (unsigned int i = 0; i < stateSize; i++)
    {
        stateVars[i] = createVar("s" + to_string(i));
    }
    for (unsigned int i = 0; i < stateSize; i++)
    {
        nextstateVars.push_back(0);
    }
    for (unsigned int i = 0; i < stateSize; i++)
    {
        nextstateVars[i] = createVar("s'" + to_string(i));
    }
    for (unsigned int i = 0; i < stateSize; i++)
    {
        transitionFunctions.push_back(0);
    }
    for (unsigned int i = 0; i < stateSize; i++)
    {
        transitionFunctions[i] = nextstateVars[i];
    }
    for (unsigned int i = 0; i < inputSize; i++)
    {
        inputVars.push_back(0);
    }
    for (unsigned int i = 0; i < inputSize; i++)
    {
        inputVars[i] = createVar("i" + to_string(i));
        cout << inputVars[i] << endl;
    }
    for (unsigned int i = 0; i < stateSize; i++)
    {
        initState.push_back(False());
    }
    cout << "Reachability Constructor Instantiated" << endl;
}
const std::vector<BDD_ID> &Reachability::getStates() const
{
    return stateVars;
}
const std::vector<BDD_ID> &Reachability::getInputs() const
{
    return inputVars;
}
bool Reachability::isReachable(const std::vector<bool> &stateVector)
{
    if (stateVars.size() != stateVector.size())
    {
        throw std::runtime_error("size does not match with number of state bits");
    }
    auto Crit = Cs;
    auto Cr = Crit;
    do
    {
        cout << "Crit: " << Crit << endl;
        Cr = Crit;
        auto imgsdash = and2(Cr, taw);
        for (unsigned long inputVar : inputVars)
        {
            imgsdash = or2(coFactorTrue(imgsdash, inputVar), coFactorFalse(imgsdash, inputVar));
        }

        for (unsigned long stateVar : stateVars)
        {
            imgsdash = or2(coFactorTrue(imgsdash, stateVar), coFactorFalse(imgsdash, stateVar));
        }

        auto imgs = imgsdash;
        // who set values to next state variables
        for (int i = 0; i < stateVars.size(); i++)
        {
            imgs = and2(imgs, xnor2(stateVars[i], nextstateVars[i]));
        }
        visualizeBDD("Reachability.dot", imgs);
        for (int i = 0; i < stateVars.size(); i++)
        {
            imgs = or2(coFactorTrue(imgs, nextstateVars[i]), coFactorFalse(imgs, nextstateVars[i]));
        }
        Crit = or2(Cr, imgs);

        cout << "Cr: " << Cr << endl;
    } while (Cr != Crit);

    // change stateVector given bu the user to a specific BDD_IDD value based on the states
    BDD_ID statevectorid = 0, temp = 0;
    statevectorid = (stateVector[0]) ? stateVars[0] : neg(stateVars[0]);
    for (int i = 1; i < stateVector.size(); i++)
    {
        temp = (stateVector[i]) ? stateVars[i] : neg(stateVars[i]);
        statevectorid = and2(statevectorid, temp);
    }
    auto restemp = and2(statevectorid, Cr);
    return (statevectorid == restemp);
}
int Reachability::stateDistance(const std::vector<bool> &stateVector)
{
    if (stateVars.size() != stateVector.size())
    {
        throw std::runtime_error("size does not match with number of state bits");
    }
    int stateDistancevar = 0;
    auto Crit = Cs;
    auto Cr = Crit;

    BDD_ID statevectorid = 0, temp = 0;
    statevectorid = (stateVector[0]) ? stateVars[0] : neg(stateVars[0]);
    for (int i = 1; i < stateVector.size(); i++)
    {
        temp = (stateVector[i]) ? stateVars[i] : neg(stateVars[i]);
        statevectorid = and2(statevectorid, temp);
    }

    if (statevectorid == Cr)
    {
        return stateDistancevar;
    }

    do
    {
        cout << "Crit: " << Crit << endl;
        Cr = Crit;
        auto imgsdash = and2(Cr, taw);
        for (unsigned long inputVar : inputVars)
        {
            imgsdash = or2(coFactorTrue(imgsdash, inputVar), coFactorFalse(imgsdash, inputVar));
        }

        for (unsigned long stateVar : stateVars)
        {
            imgsdash = or2(coFactorTrue(imgsdash, stateVar), coFactorFalse(imgsdash, stateVar));
        }

        auto imgs = imgsdash;
        // who set values to next state variables
        for (int i = 0; i < stateVars.size(); i++)
        {
            imgs = and2(imgs, xnor2(stateVars[i], nextstateVars[i]));
        }
        // visualizeBDD("Reachability.dot", imgs);
        for (int i = 0; i < stateVars.size(); i++)
        {
            imgs = or2(coFactorTrue(imgs, nextstateVars[i]), coFactorFalse(imgs, nextstateVars[i]));
        }
        stateDistancevar++;
        auto restemp = and2(statevectorid, imgs);
        if (statevectorid == restemp)
        {
            return stateDistancevar;
        }
        Crit = or2(Cr, imgs);

        cout << "Cr: " << Cr << endl;
    } while (Cr != Crit);

    return -1;
}
void Reachability::setTransitionFunctions(const std::vector<BDD_ID> &transitionFunctions)
{
    if (transitionFunctions.size() != stateVars.size())
    {
        throw std::runtime_error("size does not match with number of state bits");
    }

    for (int j = 0; j < transitionFunctions.size(); j++)
    {
        auto unkownid = transitionFunctions[j];
        if (unkownid > uniqueTableSize())
        {
            throw std::runtime_error("Unkown ID");
        }
    }

    // transition relation
    for (int i = 0; i < stateVars.size(); i++)
    {
        taw = and2(taw, or2(and2(nextstateVars[i], transitionFunctions[i]), and2(neg(nextstateVars[i]), neg(transitionFunctions[i]))));
    }
}
void Reachability::setInitState(const std::vector<bool> &stateVector)
{
    if (initState.size() != stateVector.size())
    {
        throw std::runtime_error("size does not match with number of state bits");
    }

    // change init state from default to given state
    initState = stateVector;
    for (int i = 0; i < stateVars.size(); i++)
    {
        Cs = and2(Cs, xnor2(stateVars[i], initState[i]));
    }
}