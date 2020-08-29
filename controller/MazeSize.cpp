//
// Created by Niv Swisa on 24/08/2020.
//
#include "../controller/MazeSize.h"
void MazeSize::execute(vector<string> para) {
    int size = _model->MazeSize(para[2]);
    _view->getOut() << size<<endl;

}