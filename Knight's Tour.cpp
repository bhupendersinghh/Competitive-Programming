/*
    The knight is placed on the first block of an empty board and, moving according to the rules of chess, must visit each square exactly once.
    Here : N = 8 i.e. A chessboard of dimesion 8 x 8
*/



#include<bits/stdc++.h>
#define N 8
using namespace std;

int xMoves[8] = {2, 1, -1, 2, -2, -1, -2, 1};
int yMoves[8] = {1, 2, 2, -1, -1, -2, 1, -2};

bool isPossible(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void printSol(int sol[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveKTUtil(int x, int y, int moveNo, int sol[N][N]) {
    int newX, newY;
    if(moveNo == N * N)
        return true;
    for(int i = 0; i < N; i++) {
        newX = x + xMoves[i];
        newY = y + yMoves[i];
        if(isPossible(newX, newY, sol)) {
            sol[newX][newY] = moveNo;
            if(solveKTUtil(newX, newY, moveNo + 1, sol)) {
                return true;
            }
            else {
                sol[newX][newY] = -1;
            }
        }
    }
    return false;
}

bool solveKnightsTour() {
    int sol[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            sol[i][j] = -1;
    sol[0][0] = 0;
    if(!solveKTUtil(0, 0, 1, sol)) {
        cout<<"No solution exists";
        return false;
    }
    else
        printSol(sol);
    return true;
}

int main() {
    solveKnightsTour();
    return 0;
}
