//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_SEARCHABLE_H
#define FINAL_PROJECT_SEARCHABLE_H


#include "../SearchAlgorithm/State.h"
#include <vector>

class Searchable {

public:
    virtual State getstartState() = 0;
    virtual State getGoalState() = 0;
    virtual vector<State> getAllPossibleState(State& s) = 0;
};


#endif //FINAL_PROJECT_SEARCHABLE_H
