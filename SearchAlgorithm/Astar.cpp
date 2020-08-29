//
// Created by Niv Swisa on 23/08/2020.
//


#include "../SearchAlgorithm/Astar.h"
#include <set>

Solution Astar::search(Searchable& s) {
    vector<State> moves;
    _openList.push(s.getstartState());

    auto cmp = [](State a, State b) { return a.getState() < b.getState(); };
    set<State, decltype(cmp)> closedList(cmp);
    set<State, decltype(cmp)> cpyOpen(cmp); // for adjust the praiorty in the queue.
    cpyOpen.insert(s.getstartState());
    State n;
    Position p(0, 0);
    State tmp(p);
    State goal = s.getGoalState();
    while (!(_openList.empty())) {

        State n(popOpenList());
        cpyOpen.erase(cpyOpen.find(n));

        closedList.insert(n);

        if (n == s.getGoalState()) {
            tmp = n;
            break;
        }
        // create moves successor of n.
        moves = s.getAllPossibleState(n);
        int movesSize = moves.size();

        for (int i = 0; i < movesSize; i++) {

            auto itOp = cpyOpen.find(moves[i]);
            auto itCl = closedList.find(moves[i]);
            if ((itOp == cpyOpen.end()) && (itCl == closedList.end())) {

                moves[i].setCameFrom(n); // update where we came from
                n.calculateCost(moves[i], _h->calcHeuristic(goal, moves[i])); // calculate the new move cost (+1)

                _openList.push(moves[i]); // add to open
                cpyOpen.insert(moves[i]);

            }
            else if (n.getCost() < moves[i].getCost()) {
                if (itOp == cpyOpen.end()) {
                    _openList.push(moves[i]);
                    cpyOpen.insert(moves[i]);
                }
                moves[i].setCameFrom(n);
                n.calculateCost(moves[i], _h->calcHeuristic(goal, moves[i]));
            }
        }
    }
    Solution sol;
    while (!(tmp == s.getstartState())) {
        sol.insert(tmp);
        State* f = tmp.getCameFrom();
        tmp = *f;
    }
    sol.insert(tmp);
    return sol;
}
