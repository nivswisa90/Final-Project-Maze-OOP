//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MODEL_H
#define FINAL_PROJECT_MODEL_H

#include "../Maze2d/Maze2d.h"
#include "../SearchAlgorithm/Solution.h"

class Model{
public:
    virtual void Dir(string path)=0;
    virtual void GenerateMaze(string name, int row=0, int col=0) = 0;
    virtual Maze2d display(string name) = 0;
    virtual void SaveMaze(string name,string filename) = 0;
    virtual void LoadMaze(string filename, string name) = 0;
    virtual int MazeSize(string name) = 0;
    virtual int FileSize(string name) = 0;
    virtual void SolveMaze(string name, string alg)=0;
    virtual Solution DisplaySolution(string name) = 0;
    virtual void Exit() = 0;
};

#endif //FINAL_PROJECT_MODEL_H
