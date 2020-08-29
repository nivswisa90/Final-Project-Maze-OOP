//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_BFS_H
#define FINAL_PROJECT_BFS_H

#include "../SearchAlgorithm/CommonSearcher.h"

class BFS : public CommonSearcher {
public:
    virtual Solution search(Searchable& s);
};


#endif //FINAL_PROJECT_BFS_H
