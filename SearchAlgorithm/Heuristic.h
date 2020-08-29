//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_HEURISTIC_H
#define FINAL_PROJECT_HEURISTIC_H
#include "../SearchAlgorithm/State.h"



class heuristic {
public:
    virtual double calcHeuristic(State& goal, State& s) = 0;
    virtual ~heuristic() = default;

};
class AirDistance : public heuristic {
public:
    ~AirDistance() {}
    virtual double calcHeuristic(State& goal, State& s);
};
class ManahttenDistance : public heuristic {
public:
    ~ManahttenDistance() {}
    virtual double calcHeuristic(State& goal, State& s);
};


#endif //FINAL_PROJECT_HEURISTIC_H
