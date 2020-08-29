//
// Created by Niv Swisa on 23/08/2020.
//


#include "../Maze2d/Maze2dCompression.h"

vector<int> MazeCompression::mazeCompress(Maze2d& maze) {
    string name = maze.getName();
    vector<vector<int>> myBoard = maze.getData();
    int row, col, countZero = 0, countOne = 0;
    row = maze.getrow();
    col = maze.getCol();
//first we save number of rows and number of cols and then the maze itself.
    vector<int>  arrayOFmaze;
    arrayOFmaze.push_back(row);//add rows to vector
    arrayOFmaze.push_back(col);//add cols to vector

    for (int i = 0; i < row; i++)// adds the maze
    {
        for (int k = 0; k < col; k++)
            if (myBoard[i][k] == 1) {
                countOne++;
                if (countZero != 0)
                {
                    arrayOFmaze.push_back(0);
                    arrayOFmaze.push_back(countZero);
                    countZero = 0;
                }
            }
            else {
                countZero++;
                if (countOne != 0) {
                    arrayOFmaze.push_back(1);
                    arrayOFmaze.push_back(countOne);
                    countOne = 0;
                }
            }
    }
    if (countOne > 0) {
        arrayOFmaze.push_back(1);
        arrayOFmaze.push_back(countOne);
    }
    else if (countZero > 0) {
        arrayOFmaze.push_back(0);
        arrayOFmaze.push_back(countZero);
    }
    return arrayOFmaze;
}


vector<vector<int>> MazeCompression::mazeDecompress(vector<int> compressed) {

    int row = 0, col = 0;
    //we have to reverse the vector to get the values in the right order
    reverse(compressed.begin(), compressed.end());
    row = compressed.back();
    compressed.pop_back();     // here we get the rows and cols that we save in the compress
    col = compressed.back();
    compressed.pop_back();
    vector<int> boardNumbers;// then we get the maze to a new vector
    int counter, num;
    while (!compressed.empty()) {
        num = compressed.back();
        compressed.pop_back();
        counter = compressed.back();
        compressed.pop_back();
        for (int i = 0; i < counter; i++) {
            boardNumbers.push_back(num);
        }
    }
    // we reverse the new vector and convert him to the type of Maze2d that is vector<vector<int>>
    reverse(boardNumbers.begin(), boardNumbers.end());
    vector<vector<int>> Board;
    vector<int> c(col);
    for (int k = 0; k < row; k++)
        Board.push_back(c);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            Board[i][j] = boardNumbers.back();
            boardNumbers.pop_back();
        }
    }
    return Board;// returns the BoardGame with the maze
}

void MazeCompression::save(ofstream& out, Maze2d maze) {
    //first we save all the information from to maze on the file
    int row = maze.getrow();
    int col = maze.getCol();
    out.write((char*)&row, sizeof(row));
    out.write((char*)&col, sizeof(col));

    int startX, startY, endX, endY;
    startX = maze.getStartPosition().getPositionX();
    startY = maze.getStartPosition().getPositiony();
    endX = maze.getGoalPosition().getPositionX();
    endY = maze.getGoalPosition().getPositiony();

    out.write((char*)&startX, sizeof(startX));
    out.write((char*)&startY, sizeof(startY));
    out.write((char*)&endX, sizeof(endX));
    out.write((char*)&endY, sizeof(endY));

    int n = maze.getName().length() + 1;
    out.write((char*)&n, sizeof(n));
    string name = maze.getName();
    out.write((char*)&name, n);
    vector<int> compressedMaze = this->mazeCompress(maze); //
    reverse(compressedMaze.begin(), compressedMaze.end());

    //We save the rows and cols at start of the vector and we need takeit out;
    compressedMaze.pop_back();
    compressedMaze.pop_back();

    // now we save the maze by the logic of '1' #times
    while (!(compressedMaze.empty()))
    {
        int sign = compressedMaze.back();
        out.write((char*)&sign, sizeof(sign));
        compressedMaze.pop_back();
    }
}

Maze2d MazeCompression::load(ifstream& in) {

    int row, col, n;
    Position entry, exit;
    char* name=nullptr;

    in.read((char*)&row, sizeof(row));
    in.read((char*)&col, sizeof(col));
    in.read((char*)&entry, sizeof(entry));
    in.read((char*)&exit, sizeof(exit));
    in.read((char*)&n, sizeof(n));
    if (n != 0) {
        name = new char[n + 1];
        in.read(name, n);
        name[n] = '\0';
    }

    vector<int> compressed;
    int num = 0;
    int count = 0;
    compressed.push_back(row);
    compressed.push_back(col);
    while (in.read((char*)&num, sizeof(num)))
        compressed.push_back(num);

    string nName(name);
    delete name;

    vector<vector<int>>Board = this->mazeDecompress(compressed);
    return Maze2d(nName, entry, exit, Board);

}
