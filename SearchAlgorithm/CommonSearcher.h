//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_COMMONSEARCHER_H
#define FINAL_PROJECT_COMMONSEARCHER_H

#include "../SearchAlgorithm/Searcher.h"
#include <queue>

class CommonSearcher : public Searcher {
protected:
    int _evaluatedNodes;
    priority_queue<State, vector<State>, greater<State>> _openList;

public:

    ~CommonSearcher() {}
    virtual Solution search(Searchable& s) = 0;
    CommonSearcher() : _evaluatedNodes(0) {};
    virtual int getNumOfNodesEva() { return _evaluatedNodes; }
    State popOpenList() {
        _evaluatedNodes++;
        State top = _openList.top();
        _openList.pop();
        return top;
    }
};


#endif //FINAL_PROJECT_COMMONSEARCHER_H
