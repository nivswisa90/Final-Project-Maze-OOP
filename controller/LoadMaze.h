//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_LOADMAZE_H
#define FINAL_PROJECT_LOADMAZE_H
#include "../controller/Command.h"

class LoadMaze :public Command {
private:
    view * _view;
    MyModel* _model;
public:
    LoadMaze(MyModel *model,view* view) :_model(model),_view(view) {}
    virtual void execute(vector<string> para);
};



#endif //FINAL_PROJECT_LOADMAZE_H
