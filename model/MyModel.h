//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MYMODEL_H
#define FINAL_PROJECT_MYMODEL_H


#include "../model/Model.h"
#include "../Maze2d/MyMaze2dGenerator.h"
#include "../Maze2d/SimpleMaze2dGenerator.h"
#include "../Maze2d/Maze2dCompression.h"
#include "../model/Observable.h"
#include "../SearchAlgorithm/Heuristic.h"
#include "../SearchAlgorithm/BFS.h"
#include "../SearchAlgorithm/Astar.h"
#include "../SearchAlgorithm/Maze2dSearchable.h"
#include<map>
#include <dirent.h>
class MyModel:public Model , public Observable{
    //map<string, pair<Maze2d*,Solution*>> _mazes;
    map<string , Maze2d*> _mazes;
    map<string, Solution*>_Solutions;
public:
    virtual void Dir(string path);
    virtual void GenerateMaze(string name, int row = 0, int col = 0);
    virtual Maze2d display(string name);
    virtual void SaveMaze(string name,string filename);
    virtual void LoadMaze(string filename, string name);
    virtual int MazeSize(string name);
    virtual int FileSize(string name);
    virtual void SolveMaze(string name, string alg);
    virtual Solution DisplaySolution(string name);
    virtual void Exit();
};



#endif //FINAL_PROJECT_MYMODEL_H
