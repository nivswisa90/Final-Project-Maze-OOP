//
// Created by Niv Swisa on 23/08/2020.
//
#include "../SearchAlgorithm/Heuristic.h"

double AirDistance::calcHeuristic(State& goal, State& s) {
    double currG = 0;
    double x = 0;
    double y = 0;
    currG = fabs(s.getCost() - s.getCameFrom()->getCost());
    x = abs((s.getState().getPositionX()) - (goal.getState().getPositionX()));
    y = abs((s.getState().getPositiony()) - (goal.getState().getPositiony()));
    double sqr = sqrt(pow(x, 2) + pow(y, 2));
    return sqr * currG;
}
double ManahttenDistance::calcHeuristic(State& goal, State& s) {
    double x = 0;
    double y = 0;
    x = abs((s.getState().getPositionX()) - (goal.getState().getPositionX()));
    y = abs((s.getState().getPositiony()) - (goal.getState().getPositiony()));
    x = x + y;
    return x;
}
