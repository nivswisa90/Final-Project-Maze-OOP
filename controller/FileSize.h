//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_FILESIZE_H
#define FINAL_PROJECT_FILESIZE_H
#include "../controller/Command.h"

class FileSize :public Command {
private:
    MyModel *_model;
    view* _view;
public:
    FileSize(MyModel * model,view* view):_model(model),_view(view) {};
    virtual void execute(vector<string> para);
};

#endif //FINAL_PROJECT_FILESIZE_H
