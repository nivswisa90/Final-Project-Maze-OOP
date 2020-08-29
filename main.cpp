#include <iostream>
#include "./Maze2d/Maze2d.h"

#include "./Maze2d/MyMaze2dGenerator.h"
#include "./Maze2d/Maze2dState.h"
#include "./SearchAlgorithm/BFS.h"
#include "./SearchAlgorithm/Astar.h"
#include <set>
#include "./SearchAlgorithm/Solution.h"
#include "./Maze2d/Demo.h"
//#include "Controller.h"
//#include "Model.h"
#include "./view/CLI.h"

int main() {

    CLI console(cout, cin);
    console.start();





    //    demo dem;
    //    dem.run();
    //    SimpleMaze2dGenerator gen;
    //  Maze2d maze = gen.generate("first");
    //cout << maze;
    //MyMaze2dGenerator gn;
    //Maze2d maze2 = gn.generate("second");
    //cout << maze2;
    //cout << endl;
    //MazeCompression compress;
    //vector<int> arr = compress.mazeCompress(maze2);
    ////    for( int i = 0; i < arr.size(); i++)
    ////        cout<< arr[i] <<endl;
    //MazeCompression dec;
    //vector<vector<int>> m1;
    //m1 = dec.mazeDecompress(arr);


    //ofstream myFile("try.bin", ios::binary | ios::out);
    //dec.save(myFile, maze2);
    //myFile.close();

    //Maze2d mazeReaded;
    //ifstream in_file("try.bin", ios::binary | ios::in);
    //mazeReaded = dec.load(in_file);
    //in_file.close();
    //cout << mazeReaded;



    //  string str = gn.measureAlgorithmTime();
    //  cout << str;
    //  cout << gn.measureAlgorithmTime();
    //  cout << gen.measureAlgorithmTime();

    //    Position p = maze2.getStartPosition();
    //    cout << p <<endl;
    //    cout<<maze2.getGoalPosition()<<endl;
    //    cout << maze2;
    //
    //    p.setY(5);
    //    p.setX(5);
    //    string* moves = maze2.getPossibleMoves(p);
    //    for( int i = 0; i <4; i++){
    //        if(moves[i] == "")
    //            continue;
    //        cout<<moves[i]<<endl;
    //    }
    //    State s(p);
    //    Maze2dSearchabel search(maze2);
    //    Maze2dState maze3(p);
    //    cout << maze3.calculateCost(search.getGoalState()) <<endl;
    //    vector<State> states = search.getAllPossibleState(s);
    //    for(auto & state : states)
    //        cout << state.getState() <<endl;
    //cout << s.getCost()<<endl;
    //
    //
    //    BFS bfs;
    //    Solution so;
    //
    //    so = bfs.search(search);
    //    cout<< so<<endl;
    //int cmp = [](int a, int b) { return a < b; };
    //    ManahttenDistance h;
    //    Astar astar(&h);
    //    so =  astar.search(search);
    //    cout<<so<<endl;
    //
    //
    //
    //
    return 0;
}
