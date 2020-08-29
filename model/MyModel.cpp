//
// Created by Niv Swisa on 23/08/2020.
//

#include "../model/MyModel.h"
#include "string"
void MyModel::Dir(string path) {
    const char* c=path.c_str();
    DIR *dr;
    struct dirent *en;
    dr=opendir(c);
    if(dr){
        while((en=readdir(dr))!=NULL){
            cout<<"\n"<<en->d_name;
        }
        closedir(dr);
    }
    notify();
}
void MyModel::GenerateMaze(string name, int row, int col) {
    Maze2d maze;
    MyMaze2dGenerator mg;
    Maze2d *mazePtr =new Maze2d(mg.generate(name, row, col));
    _mazes[name]= mazePtr;
    notify();
}

Maze2d MyModel::display(string name) {
//

    auto it = _mazes.find(name);
    if(_mazes[name] != nullptr){
        notify();
        return *_mazes[name];
    }

    return Maze2d();
}

void MyModel::SaveMaze(string name,string filename) {
    MazeCompression compress;
    ofstream myFile(filename, ios::binary | ios::out);
    compress.save(myFile,*_mazes[name]);
    myFile.close();
    notify();
}

void MyModel::Exit() {
    exit(0);
}

void MyModel::LoadMaze(string filename, string name) {
    MazeCompression decompress;
    ifstream in_file(filename, ios::binary | ios::in);
    Maze2d* maze=new Maze2d();
    *maze = decompress.load(in_file);
    in_file.close();
    if(_mazes[name]== nullptr)
        _mazes[name]=maze;
    else
        cout<<"Exist a maze with that name"<<endl;
    notify();

}

int MyModel::MazeSize(string name) {
    auto it = _mazes.find(name);
    if(it == _mazes.end())
        return 0;
    notify();
    int size = sizeof(it->first);
    return size;
}

int MyModel::FileSize(string name) {
    auto it = _mazes.find(name);
    if(it == _mazes.end())
        return 0;
    MazeCompression compression;
    ofstream myFile("try.bin", ios::binary | ios::out);
    compression.save(myFile,*it->second);
    return sizeof(myFile);
}

void MyModel::SolveMaze(string name, string alg) {
    Solution *so=new Solution();
    auto it = _mazes.find(name);
    if(it == _mazes.end())
        return;
    Maze2dSearchabel SearchMaze(*_mazes[name]);
    if(_Solutions[name] == nullptr)
    {
        if(alg == "astar")
        {
            ManahttenDistance h;
            Astar astar(&h);
            *so = astar.search(SearchMaze);
            _Solutions[name] = so;
        }
        else if(alg  == "bfs") {
            BFS bfs;
            *so = bfs.search(SearchMaze);
            _Solutions[name] = so;
        }
    }
}

Solution MyModel::DisplaySolution(string name) {
    auto it = _Solutions.find(name);
    if(_Solutions[name] != nullptr){
        notify();
        return *_Solutions[name];
    }
    return Solution();
}
