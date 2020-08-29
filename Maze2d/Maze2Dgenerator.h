//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MAZE2DGENERATOR_H
#define FINAL_PROJECT_MAZE2DGENERATOR_H

#include <iostream>
#include <vector>
#include <random>
using namespace std;
#include "../Maze2d/Maze2d.h"

class Maze2Dgenerator {
public:
    virtual Maze2d generate(string name, int rows = 0, int cols = 0) = 0;
    virtual string measureAlgorithmTime() = 0;
};


#endif //FINAL_PROJECT_MAZE2DGENERATOR_H
