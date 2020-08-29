//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_CONTROLLER_H
#define FINAL_PROJECT_CONTROLLER_H
#include<map>
#include "../Maze2d/Maze2d.h"
#include "../view/view.h"
#include "../controller/Command.h"
#include "../model/Model.h"

using namespace std;

class Command;
class Controller {
public:
    virtual Command* get(const string& command)=0;
};

#endif //FINAL_PROJECT_CONTROLLER_H
