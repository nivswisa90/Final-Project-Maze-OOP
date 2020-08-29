//
// Created by Niv Swisa on 23/08/2020.
//

#include <iostream>
#include "../Maze2d/SimpleMaze2dGenerator.h"

Maze2d SimpleMaze2dGenerator::generate(string name, int rows, int cols) {
    int width = 0;
    int height = 0;
    //if user does not give size we randomize it
    srand(time(nullptr));
    if (rows == 0 || cols == 0)
    {
        width = (rand() % 51) + 10;
        height = (rand() % 31) + 10;
    }
    else {
        width = cols;
        height = rows;
    }

    vector<vector<int>> maze;
    vector<int> col(width);
    //initial
    for (int i = 0; i < height; i++) {
        maze.push_back(col);
    }
    //initial with 1
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = 1;
        }
    }
    //randomize start point from the left side of the matrix
    srand(time(nullptr));
    int startX;
    startX = rand() % (height - 2) + 1;
    Position start(startX, 0);
    maze[startX][0] = 0;
    int i = 0;
    maze[startX][1] = 0;
    for (i = 1; i < (width - 1);) {
        int direct = rand() % 3;
        //adding exit to maze
        if (width - 2 == i) {
            maze[startX][width - 1] = 0;
            i++;
        }
        else { //  checks all possible moves that the maze can go
            if (direct == 0 && startX > 2)
                maze[--startX][i] = 0;
            if (direct == 1)
                maze[startX][++i] = 0;
            if (direct == 2 && startX < height - 2)
                maze[++startX][i] = 0;
        }
    }
    //getting exit point on the right side of the maze
    Position exit(startX, width - 1);
    // adding some roots in the maze to get it more randomize and more complicated
    int paths = 3;
    while (paths--) {
        int rnd = (rand() % (width - 2) + 1);
        int rnd2 = (rand() % (height - 2) + 1);
        for (int k = 1; k < height - 2; k++) {
            maze[k][rnd] = 0;
        }
        for (int k = 1; k < width - 2; k++) {
            maze[rnd2][k] = 0;
        }
    }
    return Maze2d(name, start, exit, maze);
}
