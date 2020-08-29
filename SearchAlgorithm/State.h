//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_STATE_H
#define FINAL_PROJECT_STATE_H

#include <memory>
#include <string>
#include "../Maze2d/Position.h"
#include <math.h>


using namespace std;

//template <class T>
class State {
protected:
    Position _state;
    double _cost;
    State* _cameFrom;

public:
    State() {}

    State(const State& s) : _state(s._state), _cost(s._cost), _cameFrom(s._cameFrom) {};

    State(Position state) : _state(state), _cost(0), _cameFrom(nullptr) {};

    ~State() {
        //delete _cameFrom;
    };

public:

    Position getState() { return _state; };

    double getCost() const { return _cost; };

    State* getCameFrom() { return _cameFrom; }

    void setCameFrom(const State& cameFrom) { _cameFrom = new State(cameFrom); }

    double calculateCost(State& targetState, double heuristic = 0) {
        targetState._cost = _cost + 1 + heuristic;
        return _cost + 1;
    }


    bool operator==(const State& s) const { return _state == s._state; }

    State& operator=(const State& s) {
        _state = s._state;
        _cost = s._cost;
        _cameFrom = s._cameFrom;
        return *this;
    }

    bool operator<(const State& s1) const {
        return _cost < s1._cost;
    }

    bool operator>(const State& s) const {
        return _cost > s._cost;
    }

    friend ostream& operator<<(ostream& out, const State& s) {
        out << s._state << " " << s._cost << " " << s._cameFrom << endl;
        return out;
    }
};


#endif //FINAL_PROJECT_STATE_H
