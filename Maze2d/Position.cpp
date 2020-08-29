//
// Created by Niv Swisa on 23/08/2020.
//

#include "../Maze2d/Position.h"

//
//  overload operators
//
ostream& operator<<(ostream& out, const Position& p) {
    out << "{" << p.getPositionX() << "," << p.getPositiony() << "}";
    return out;
}

Position& Position::operator=(const Position& p) {
    _x = p._x;
    _y = p._y;
    return *this;
}

bool Position::operator==(const Position& p) const {
    return ((_x == p._x) && (_y == p._y));
}

bool Position::operator<(const Position& p) const {
    bool t = false;

    if (_y == p._y) {
        if (_x < p._x)
            t = true;
    }
    else if (_y < p._y)
        t = true;

    return t;
}
