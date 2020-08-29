//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_DISPLAY_H
#define FINAL_PROJECT_DISPLAY_H
#include "../controller/Command.h"

class Display:public Command {
private:
   MyModel *_model;
   view *_view;
public:
    Display(MyModel* model,view* view) :_model(model),_view(view){}
    virtual void execute(vector<string> para);
};


#endif //FINAL_PROJECT_DISPLAY_H
