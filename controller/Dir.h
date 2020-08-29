//
// Created by Niv Swisa on 25/08/2020.
//

#ifndef FINAL_PROJECT_DIR_H
#define FINAL_PROJECT_DIR_H

#include "../controller/Command.h"
class Dir:public Command {
private:
    MyModel* _model;
    view* _view;
public:
    Dir(MyModel* model,view* view):_model(model),_view(view){}
    virtual void execute(vector<string> para);
};


#endif //FINAL_PROJECT_DIR_H
