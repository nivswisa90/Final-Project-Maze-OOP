//
// Created by Niv Swisa on 23/08/2020.
//

#include "../SearchAlgorithm/Solution.h"

ostream& operator <<(ostream& out, Solution& s) {
    auto it = s._Solution.begin();
    string str;
    int count = 0;
    while (it != s._Solution.end()) {
        out << " " << it->getState();
        it++;
    }
    return out;
}
