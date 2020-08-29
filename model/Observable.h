//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_OBSERVABLE_H
#define FINAL_PROJECT_OBSERVABLE_H
#include "../model/Observer.h"
#include <vector>
using namespace std;
class Observable {
protected:
    vector<Observer*> _observers;
public:
    void addObserver(Observer& o) {
        _observers.push_back(&o);
    }
    void notify() {
        for (auto it = _observers.begin(); it != _observers.end(); ++it)
            (*it)->Update(*this);
    }
};

#endif //FINAL_PROJECT_OBSERVABLE_H
