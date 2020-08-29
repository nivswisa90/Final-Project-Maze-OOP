//
// Created by Niv Swisa on 25/08/2020.
//

#include "../controller/Dir.h"
void Dir::execute(vector<string> para) {
    if(para.size()>2){
        cout<<"Wrong number of paths"<<endl;
        return;
    }
    _model->Dir(para[1]);
    //string path = para.back();
    //_view->getOut() << path;
}