//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_COMMAND_H
#define FINAL_PROJECT_COMMAND_H
#include "../view/view.h"
#include "../Maze2d/Maze2d.h"
#include "../model/MyModel.h"

class Command {
public:
    virtual void execute(vector<string> para) = 0;
};



#endif //FINAL_PROJECT_COMMAND_H
