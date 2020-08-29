//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_SAVEMAZE_H
#define FINAL_PROJECT_SAVEMAZE_H

#include "../controller/Command.h"

class SaveMaze : public Command {
private:
    view * _view;
    MyModel* _model;


public:
    SaveMaze(MyModel* model,view* view) :_model(model),_view(view) {}

//SaveMaze(MyModel *model,view *view) :_model(model),_view(view) {}
    virtual void execute(vector<string> para);
};

//void SaveMaze::execute() {
//    _model->SaveMaze("sec");
//
//}

#endif //FINAL_PROJECT_SAVEMAZE_H
