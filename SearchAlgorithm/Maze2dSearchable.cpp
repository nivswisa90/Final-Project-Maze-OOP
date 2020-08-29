//
// Created by Niv Swisa on 23/08/2020.
//


#include "../SearchAlgorithm/Maze2dSearchable.h"

vector<State> Maze2dSearchabel::getAllPossibleState(State& s) {
    vector<State> states;
    Position p = s.getState();
    Position tmp;
    string* Moves = _maze.getPossibleMoves(p);
    //represent possible moves by directions "Down","up"... not by points
    for (int i = 0; i < 4; i++) {
        if (Moves[i] == "Down") {
            tmp.setX(p.getPositionX() + 1);
            tmp.setY(p.getPositiony());
            states.emplace_back(tmp);
        }
        if (Moves[i] == "Up") {
            tmp.setX(p.getPositionX() - 1);
            tmp.setY(p.getPositiony());
            states.emplace_back(tmp);
        }
        if (Moves[i] == "Right") {
            tmp.setX(p.getPositionX());
            tmp.setY(p.getPositiony() + 1);
            states.emplace_back(tmp);
        }
        if (Moves[i] == "Left") {
            tmp.setX(p.getPositionX());
            tmp.setY(p.getPositiony() - 1);
            states.emplace_back(tmp);
        }
    }
    if (states.empty())
        cout << "No possible moves" << endl;
    return states;
}
