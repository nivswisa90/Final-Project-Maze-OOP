//
// Created by Niv Swisa on 24/08/2020.
//

#include "../controller/FileSize.h"

void FileSize::execute(vector<string> para) {
    int size = _model->FileSize(para[2]);
    _view->getOut() << size<<endl;

}

