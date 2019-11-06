#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <QList>




class BackTracking
{
public:
    BackTracking();
    int N=10;
    int solucion[10][10];
    void guardar_solucion(int sol[10][10]);
    bool solveMaze(int maze[10][10],int xi,int yi);
    bool solveMazeUtil(int maze[10][10], int x, int y, int sol[10][10]);
    bool isSafe(int maze[10][10], int x, int y);
};

#endif // BACKTRACKING_H
