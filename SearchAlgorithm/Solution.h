//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_SOLUTION_H
#define FINAL_PROJECT_SOLUTION_H


#include "../SearchAlgorithm/State.h"
#include <vector>
#include <iostream>

class Solution {
private:
    vector<State > _Solution;
public:
    Solution() {};
    Solution(vector<State> s)
    {
        _Solution.assign(s.begin(), s.end());
    }
    ~Solution() {};
    vector<State> getSolution() { return _Solution; }
    friend ostream& operator <<(ostream& out, Solution& s);
    void insert(State& s) { _Solution.insert(_Solution.begin(), s); }
};



#endif //FINAL_PROJECT_SOLUTION_H
