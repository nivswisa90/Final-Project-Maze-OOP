//
// Created by Niv Swisa on 23/08/2020.
//
#include "../Maze2d/Maze2d.h"

//
//    Constructors
//


Maze2d::Maze2d(const Maze2d& maze) {
    *this = maze;
}
//
//   overload operators
//
ostream& operator<<(ostream& out, const Maze2d& maze) {
    string str;
    for (int i = 0; i < maze._BoardGame.size(); i++) {
        for (int j = 0; j < maze._BoardGame[0].size(); j++) {
            if (maze._BoardGame[i][j] == 1)
                str += "1 ";
            else
                str += "0 ";
        }
        str += '\n';
    }
    return out << str;
}

Maze2d& Maze2d::operator=(const Maze2d& maze) {
    _name = maze._name;
    _entry = maze._entry;
    _exit = maze._exit;
    _BoardGame = maze._BoardGame;
    return *this;
}

string* Maze2d::getPossibleMoves(const Position& p) const {
    string* moves = new string[4];
    for (int i = 0; i < 4; i++) {
        moves[i] = "";
    }
    if (p.getPositionX() < 0 || p.getPositionX() > _BoardGame.size() || p.getPositiony() < 0 ||
        p.getPositiony() > _BoardGame[0].size()) {
        return (string*)"invalid position";
    }
    else if (_BoardGame[p.getPositionX()][p.getPositiony()] == 1) {
        return (string*)"This is a wall";
    }
    else {
        if (p.getPositionX() + 1 < _BoardGame.size()) {
            if (_BoardGame[p.getPositionX() + 1][p.getPositiony()] == 0) {
                moves[0] = "Down";
            }
        }
        if (p.getPositionX() - 1 > -1) {
            if (_BoardGame[p.getPositionX() - 1][p.getPositiony()] == 0) {
                moves[1] = "Up";
            }
        }
        if (p.getPositiony() + 1 < _BoardGame[0].size()) {
            if (_BoardGame[p.getPositionX()][p.getPositiony() + 1] == 0) {
                moves[2] = "Right";
            }
        }
        if (p.getPositiony() - 1 > 0) {
            if (_BoardGame[p.getPositionX()][p.getPositiony() - 1] == 0) {
                moves[3] = "Left";
            }
        }
    }
    return moves;
}
