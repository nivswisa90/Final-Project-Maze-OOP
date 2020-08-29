//
// Created by Niv Swisa on 24/08/2020.
//
#include "../controller/LoadMaze.h"
void LoadMaze::execute(vector<string> para) {
    _model->LoadMaze(para[2],para[3]);
}
