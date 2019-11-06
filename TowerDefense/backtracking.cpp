#include "backtracking.h"
#include <QDebug>


#include<stdio.h>

// Maze size


BackTracking::BackTracking()
{

}



/* A utility function to print solution matrix sol[N][N] */
void BackTracking::guardar_solucion(int sol[10][10])
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            solucion[j][i]=sol[j][i];
        }
    }
}

/* A utility function to check if x,y is valid index for N*N maze */
bool BackTracking::isSafe(int maze[10][10], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[y][x] == 1){
        return true;
    }

    return false;
}

bool BackTracking::solveMaze(int maze[10][10], int xi, int yi)
{
    int sol[10][10];
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            sol[j][i]=0;
        }
    }
    if(solveMazeUtil(maze, xi, yi, sol) == false)
    {
        qDebug() << ("Solution doesn't exist");
        return false;
    }


    guardar_solucion(sol);
    qDebug() << ("Solucion creada");
    return true;
}

/* A recursive utility function to solve Maze problem */
bool BackTracking::solveMazeUtil(int maze[10][10], int x, int y, int sol[10][10])
{
    // if (x,y is goal) return true
    if(x == N-1 && y == 0)
    {
        sol[y][x] = 1;
        return true;
    }
    qDebug()<<QString::number(x)+" , "+QString::number(y);

    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y) == true)
    {
        // mark x,y as part of solution path
        sol[y][x] = 1;

        /* Move forward in x direction */
        if (solveMazeUtil(maze, x+1, y, sol) == true){
//            qDebug()<<"me muevo a la derecha";
            return true;}

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y-1, sol) == true){
//            qDebug()<<"me muevo arriba";
            return true;
        }



        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[y][x] = 0;
//        qDebug()<<"no logrè moverme";
//        qDebug()<<QString::number(x)+" , "+QString::number(y)+"encerrado";

        //a partir de aqui borrar
//        int nuevomaze[10][10];
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = 0; j < N; j++){
//                nuevomaze[i][j]=maze[i][j];
//            }
//        }
//            nuevomaze[y][x]=0;
//        if (maze[y+1][x]!=0){
//            if (solveMazeUtil(nuevomaze, x, y+1, sol) == true){
//                qDebug()<<"me muevo arriba";
//                return true;
//            }
//        }
//        if (maze[y][x-1]!=0){
//            if (solveMazeUtil(nuevomaze, x-1, y, sol) == true){
//                qDebug()<<"me muevo a la izquierda";
//                return true;}
//        }
        //hasta aca si no funcionara
        return false;
    }
    qDebug()<<"no estoy a salvo";
    return false;
}
