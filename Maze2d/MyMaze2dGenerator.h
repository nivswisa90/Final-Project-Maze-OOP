//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MYMAZE2DGENERATOR_H
#define FINAL_PROJECT_MYMAZE2DGENERATOR_H

#include "../Maze2d/Maze2dGeneratorABS.h"
class MyMaze2dGenerator : public Maze2dGeneratorABS {
public:
    virtual Maze2d generate(string name, int rows = 0, int cols = 0);
};


#endif //FINAL_PROJECT_MYMAZE2DGENERATOR_H
