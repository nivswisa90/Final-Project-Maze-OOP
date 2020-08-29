//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_SEARCHER_H
#define FINAL_PROJECT_SEARCHER_H


#include "../SearchAlgorithm/Solution.h"
#include "../SearchAlgorithm/Searchable.h"

class Searcher {
public:
    virtual Solution search(Searchable& s) = 0;
    virtual int getNumOfNodesEva() = 0;
};


#endif //FINAL_PROJECT_SEARCHER_H
