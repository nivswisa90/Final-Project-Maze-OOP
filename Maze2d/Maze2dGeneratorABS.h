//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MAZE2DGENERATORABS_H
#define FINAL_PROJECT_MAZE2DGENERATORABS_H


#include "../Maze2d/Maze2Dgenerator.h"
#include <chrono>
using namespace std;


class Maze2dGeneratorABS : public Maze2Dgenerator {
public:
    virtual Maze2d generate(string name, int rows = 0, int cols = 0) = 0;
    virtual string measureAlgorithmTime();

};



#endif //FINAL_PROJECT_MAZE2DGENERATORABS_H
