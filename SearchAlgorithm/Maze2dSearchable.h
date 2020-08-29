//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MAZE2DSEARCHABLE_H
#define FINAL_PROJECT_MAZE2DSEARCHABLE_H

#include "../SearchAlgorithm/Searchable.h"
#include "../Maze2d/Maze2d.h"

class Maze2dSearchabel : public Searchable {
private:
    Maze2d _maze;
public:
    Maze2dSearchabel(const Maze2d& maze) : _maze(maze) {};

    virtual State getstartState() {
        State s(_maze.getStartPosition());
        return s;
    }

    virtual State getGoalState() {
        State s(_maze.getGoalPosition());
        return s;
    }

    virtual vector<State> getAllPossibleState(State& s);
};


#endif //FINAL_PROJECT_MAZE2DSEARCHABLE_H
