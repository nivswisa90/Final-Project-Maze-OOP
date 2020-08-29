//
// Created by Niv Swisa on 24/08/2020.
//

#include "../controller/DisplaySolution.h"

void DisplaySolution::execute(vector <string> para) {
    Solution so;
    so = _model->DisplaySolution(para[2]);
    _view->getOut() <<so << endl;
}

