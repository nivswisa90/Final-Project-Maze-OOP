//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_OBSERVER_H
#define FINAL_PROJECT_OBSERVER_H

class Observable;
class Observer {
public:
    virtual void Update(Observable& o)=0;
};

#endif //FINAL_PROJECT_OBSERVER_H
