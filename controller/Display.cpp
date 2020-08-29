//
// Created by Niv Swisa on 23/08/2020.
//

#include "../controller/Display.h"

void Display::execute(vector<string> para)
{
    if(para.size()>2){
        cout<<"You must insert less parameters"<<endl;
        return;
    }
    Maze2d  maze;
    maze = _model->display(para[1]);
    _view->getOut() << maze;

    //cout<<_model<<endl;
}
