//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_POSITION_H
#define FINAL_PROJECT_POSITION_H
#include <iostream>

using namespace std;

class Position {
private:
    int _x;
    int _y;
public:
    Position() : _x(0), _y(0) {}

    Position(int x, int y) : _x(x), _y(y) {}

    ~Position() {};

    int getPositionX() const { return _x; }

    int getPositiony() const { return _y; }

    void setX(int x) { _x = x; }

    void setY(int y) { _y = y; }

    friend ostream& operator<<(ostream& out, const Position& p);

    Position& operator=(const Position& p);

    bool operator==(const Position& p) const;

    bool operator<(const Position& p) const;
};



#endif //FINAL_PROJECT_POSITION_H
