//
// Created by Niv Swisa on 24/08/2020.
//

#include "../controller/SolveMaze.h"

void SolveMaze::execute(vector<string> para) {
    _model->SolveMaze(para[1],para[2]);

}

