//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_ASTAR_H
#define FINAL_PROJECT_ASTAR_H


#include "../SearchAlgorithm/CommonSearcher.h"
#include "../SearchAlgorithm/Heuristic.h"


class Astar :public CommonSearcher {
private:
    heuristic* _h;
public:
    Astar(heuristic* h) {
        _h = h;
    }
    ~Astar() {}
    Solution search(Searchable& s);

};

#endif //FINAL_PROJECT_ASTAR_H
