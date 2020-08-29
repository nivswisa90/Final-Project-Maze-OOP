//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MAZE2D_H
#define FINAL_PROJECT_MAZE2D_H

#include <string>
#include <utility>
#include <vector>
#include "../Maze2d/Position.h"


using namespace std;


class Maze2d {
protected:
    string _name;
    Position _entry;
    Position _exit;
    vector<vector<int>> _BoardGame;


public:
    Maze2d() {};
    Maze2d(string name, Position entry, Position exit, vector<vector<int>> maze): _name(name),
    _entry(entry),
    _exit(exit),
    _BoardGame(maze) {};


    Maze2d(const Maze2d& maze);

    ~Maze2d() {};

    string* getPossibleMoves(const Position& p) const;

    Position getStartPosition() { return _entry; };

    Position getGoalPosition() { return _exit; };

    int getCol() {
        return _BoardGame[0].size();
    }

    int getrow() {
        return _BoardGame.size();
    }

    string getName() { return _name; };

    vector<vector<int>> getData() { return _BoardGame; };

    friend ostream& operator<<(ostream& out, const Maze2d& maze);

    Maze2d& operator=(const Maze2d& maze);
};



#endif //FINAL_PROJECT_MAZE2D_H
