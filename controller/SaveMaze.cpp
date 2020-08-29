//
// Created by Niv Swisa on 24/08/2020.
//

#include "../controller/SaveMaze.h"

void SaveMaze::execute(vector<string> para) {
   _model->SaveMaze(para[2],para[3]);

}

