//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MAZE2DSTATE_H
#define FINAL_PROJECT_MAZE2DSTATE_H

#include "../SearchAlgorithm/State.h"
//template <class T>
class Maze2dState : public State {
public:
    Maze2dState(Position state) : State(state) {};
    ~Maze2dState() = default;
};


#endif //FINAL_PROJECT_MAZE2DSTATE_H
