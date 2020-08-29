//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_DISPLAYSOLUTION_H
#define FINAL_PROJECT_DISPLAYSOLUTION_H


#include "../controller/Command.h"

class DisplaySolution : public Command {
private:
    view * _view;
    MyModel* _model;
public:
    DisplaySolution(MyModel *model,view* view) :_model(model),_view(view) {}
    virtual void execute(vector<string> para);
};


#endif //FINAL_PROJECT_DISPLAYSOLUTION_H
