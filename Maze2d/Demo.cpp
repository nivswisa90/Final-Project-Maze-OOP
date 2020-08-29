//
// Created by Niv Swisa on 23/08/2020.
//

#include "../Maze2d/MyMaze2dGenerator.h"

#include "../SearchAlgorithm/BFS.h"
#include "../SearchAlgorithm/Astar.h"
#include "../Maze2d/Demo.h"
#include "../SearchAlgorithm/Maze2dSearchable.h"
void demo::run() {
    MyMaze2dGenerator  mg;
    Maze2d maze = mg.generate("DemoMaze");
    cout << maze;
    Maze2dSearchabel search(maze);
    BFS bfs;
    Solution so;
    so = bfs.search(search);
    cout << "Solution of BFS" << endl;
    cout << so << endl;
    cout << "Number of nodes  evaluated is " << bfs.getNumOfNodesEva() << endl;
    ManahttenDistance h1;
    Astar astar(&h1);
    so = astar.search(search);
    cout << "Solution of A* with h = ManahttenDistance" << endl;
    cout << so << endl;
    cout << "Number of nodes  evaluated is " << astar.getNumOfNodesEva() << endl;
    AirDistance h2;
    Astar astar2(&h2);
    so = astar2.search(search);
    cout << "Solution of A* with h = Air distance" << endl;
    cout << so << endl;
    cout << "Number of nodes  evaluated is " << astar2.getNumOfNodesEva() << endl;




}
