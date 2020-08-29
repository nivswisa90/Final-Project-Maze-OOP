//
// Created by Niv Swisa on 23/08/2020.
//

#include <stack>
#include "../Maze2d/MyMaze2dGenerator.h"

Maze2d MyMaze2dGenerator::generate(string name, int rows, int cols) {
    int width = 0;
    int height = 0;
    srand(time(nullptr));
    if (rows == 0 || cols == 0) {
        width = (rand() % 51) + 10;
        height = (rand() % 31) + 10;
    }
    else {
        width = cols;
        height = rows;
    }
    vector<vector<int>> maze;
    vector<int> col(width);
    //initial
    for (int i = 0; i < height; i++) {
        maze.push_back(col);
    }
    //initial with 1 for borders
    for (int i = 0; i < width; i++) {
        maze[0][i] = 1;
        maze[height - 1][i] = 1;
    }
    for (int j = 0; j < height; j++) {
        maze[j][0] = 1;
        maze[j][width - 1] = 1;
    }
    // initial with 2 to middle of the maze
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            maze[i][j] = 2;
        }
    }
    stack<Position> s;
    // randomize start Position
    srand(time(nullptr));
    int startX = 0;
    int startY = 0;
    int whereTostart = rand() % 2;
    Position start;
    if (whereTostart == 0) {
        startX = rand() % (height - 2) + 1;
        start.setX(startX);
        start.setY(0);

        maze[startX][startY] = 0;
    }
    else {
        startY = rand() % (width - 2) + 1;
        start.setX(0);
        start.setY(startY);
        maze[startX][startY] = 0;
    }
    s.push(start);
    Position curr;
    Position tmp;
    while (!s.empty()) {
        curr = s.top();
        s.pop();
        maze[curr.getPositionX()][curr.getPositiony()] = 0;
        vector<Position> arr;
        int i = 0;
        //3 means seen the neighbors
        if (curr.getPositionX() + 1 < height - 1) {
            if (maze[curr.getPositionX() + 1][curr.getPositiony()] == 2) {
                maze[curr.getPositionX() + 1][curr.getPositiony()] = 3;
                tmp.setX(curr.getPositionX() + 1);
                tmp.setY(curr.getPositiony());
                arr.push_back(tmp);
                i++;
            }
        }
        if (curr.getPositionX() - 1 > 0) {
            if (maze[curr.getPositionX() - 1][curr.getPositiony()] == 2) {
                maze[curr.getPositionX() - 1][curr.getPositiony()] = 3;
                tmp.setX(curr.getPositionX() - 1);
                tmp.setY(curr.getPositiony());
                arr.push_back(tmp);
                i++;
            }
        }
        if (curr.getPositiony() + 1 < width - 1) {
            if (maze[curr.getPositionX()][curr.getPositiony() + 1] == 2) {
                maze[curr.getPositionX()][curr.getPositiony() + 1] = 3;
                tmp.setX(curr.getPositionX());
                tmp.setY(curr.getPositiony() + 1);
                arr.push_back(tmp);
                i++;
            }
        }
        if (curr.getPositiony() - 1 > 0) {
            if (maze[curr.getPositionX()][curr.getPositiony() - 1] == 2) {
                maze[curr.getPositionX()][curr.getPositiony() - 1] = 3;
                tmp.setX(curr.getPositionX());
                tmp.setY(curr.getPositiony() - 1);
                arr.push_back(tmp);
            }
        }
        Position used;
        used.setY(1000); // random value to understand if we allready saw this location from the other side
        used.setX(1000);
        int counter = 0;

        while (counter < i) {
            int rnd = rand() % 4;
            if (rnd == 0 && !arr.empty()) {
                if ((arr[0].getPositionX() != used.getPositionX()) && (arr[0].getPositiony() != used.getPositiony()) &&
                    maze[arr[0].getPositionX()][arr[0].getPositiony()] == 3) {
                    tmp = arr[0];
                    arr[0] = used;
                    s.push(tmp);
                    ++counter;
                }
            }
            if (rnd == 1 && arr.size() > 1) {
                if ((arr[1].getPositionX() != used.getPositionX()) && (arr[1].getPositiony() != used.getPositiony()) &&
                    maze[arr[1].getPositionX()][arr[1].getPositiony()] == 3) {
                    tmp = arr[1];
                    arr[1] = used;
                    s.push(tmp);
                    ++counter;
                }
            }
            if (rnd == 2 && arr.size() > 2) {
                if ((arr[2].getPositionX() != used.getPositionX()) && (arr[2].getPositiony() != used.getPositiony()) &&
                    maze[arr[2].getPositionX()][arr[2].getPositiony()] == 3) {
                    tmp = arr[2];
                    arr[2] = used;
                    s.push(tmp);
                    ++counter;
                }
            }
            if (rnd == 3 && arr.size() == 4) {
                if ((arr[3].getPositionX() != used.getPositionX()) &&
                    (arr[3].getPositiony() != used.getPositiony()) &&
                    maze[arr[3].getPositionX()][arr[3].getPositiony()] == 3) {
                    tmp = arr[3];
                    arr[3] = used;
                    s.push(tmp);
                    ++counter;
                }
            }
        }
        if (s.size() > 0) {
            curr = s.top();
        }
        //intitiall all leftovers that we saw allready to a wall('1')
        if (maze[curr.getPositionX() + 1][curr.getPositiony()] == 3)
            maze[curr.getPositionX() + 1][curr.getPositiony()] = 1;
        if (maze[curr.getPositionX() - 1][curr.getPositiony()] == 3)
            maze[curr.getPositionX() - 1][curr.getPositiony()] = 1;
        if (maze[curr.getPositionX()][curr.getPositiony() + 1] == 3)
            maze[curr.getPositionX()][curr.getPositiony() + 1] = 1;
        if (maze[curr.getPositionX()][curr.getPositiony() - 1] == 3)
            maze[curr.getPositionX()][curr.getPositiony() - 1] = 1;
        arr.clear();
    }
    Position exit;
    // checking for exit point, if its from to down side or just from the side, all mazes start from top or right side
    while (exit.getPositionX() == 0 && exit.getPositiony() == 0) {
        if (startX != 0)
        {
            int out1 = (rand() % (height - 2) + 1);
            if (maze[out1][width - 2] == 0) {
                maze[out1][width - 1] = 0;
                exit.setX(out1);
                exit.setY(width - 1);
            }
        }
        if (startY != 0)
        {
            int out1 = (rand() % (width - 2) + 1);
            if (maze[height - 2][out1] == 0) {
                maze[height - 1][out1] = 0;
                exit.setX(height - 1);
                exit.setY(out1);
            }
        }
    }
    return Maze2d(name, start, exit,/* start,*/ maze);
}
