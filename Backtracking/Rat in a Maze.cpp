/*
    There is a maze of 4 x 4 dimension, 0 denotes the blocks where the rat can't go to. If the starting point if (0, 0)
    and the rat is only allowed to move forward or downward, find the solution to the maze; 
*/


#include<bits/stdc++.h>
#define N 4
using namespace std;

int xMoves[8] = {2, 1, -1, 2, -2, -1, -2, 1};
int yMoves[8] = {1, 2, 2, -1, -1, -2, 1, -2};

bool isPossible(int x, int y, int maze[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

void printSol(int sol[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    if(x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    if(isPossible(x, y, maze)) {
        sol[x][y] = 1;
        if(solveMazeUtil(maze, x + 1, y, sol))
            return true;
        if(solveMazeUtil(maze, x, y + 1, sol))
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };
    if(solveMazeUtil(maze, 0, 0, sol)) {
        printSol(sol);
        return true;
    }
    else {
        cout<<"No Solution";
        return false;
    }
}

int main() {
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };

    solveMaze(maze);
    return 0;
}
