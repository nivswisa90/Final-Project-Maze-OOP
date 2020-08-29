//
// Created by Niv Swisa on 23/08/2020.
//
#include "../controller/GenerateMazeCommand.h"

void GenerateMazeCommand::execute(vector<string> para)
{
    if(para.size()>5){
        cout<<"You must insert less parameters"<<endl;
        return;
    }
    string name = para[2];
    int row= stoi(para[3]),col=stoi(para[4]);
    _model->GenerateMaze(name,row,col);
}
