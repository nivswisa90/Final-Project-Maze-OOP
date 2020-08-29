//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_VIEW_H
#define FINAL_PROJECT_VIEW_H
#include<iostream>

class view {
public:
    virtual void start() = 0;
    virtual std::ostream& getOut() = 0;
};

#endif //FINAL_PROJECT_VIEW_H
