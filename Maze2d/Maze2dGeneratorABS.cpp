//
// Created by Niv Swisa on 23/08/2020.
//

#include "../Maze2d/Maze2dGeneratorABS.h"

string Maze2dGeneratorABS::measureAlgorithmTime() {
    auto start = chrono::steady_clock::now();
    Maze2d maze = generate("firs");
    auto end = chrono::steady_clock::now();
    int  time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    string str = "Elapsed time to make a maze in nanoseconds :" + to_string(time);
    return str;
}
