//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MAZE2DCOMPRESSION_H
#define FINAL_PROJECT_MAZE2DCOMPRESSION_H

#include <iostream>
#include <cstring>
#include "../Maze2d/Maze2d.h"
#include<fstream>


using namespace std;


class MazeCompression {
public:
    MazeCompression() {};
    ~MazeCompression() {};
    vector<int> mazeCompress(Maze2d& maze);
    vector<vector<int>> mazeDecompress(vector<int> compressed);
    Maze2d load(ifstream& in);
    void save(ofstream& out, Maze2d maze);
};



#endif //FINAL_PROJECT_MAZE2DCOMPRESSION_H
