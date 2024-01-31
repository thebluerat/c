#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define INIT_VALUE -1

#define START 'S' //시작점
#define GOAL 'G' //탈출구
#define WAY ' ' //길
#define WALL '#' //벽
#define MARKED '+' //탈출구로 향하는 길 표식

enum DIRECTION {NORTH, SOUTH, EAST, WEST};
enum RESULT {FAIL, SUCCEED};

typedef struct tagPosition
{
	int X;
	int Y;
} Position;

typedef struct tagMazeSize
{
	int ColumnSize; //너비
	int RowSize; //높이
		 
	char** Data; //동적으로 할당한 2차원 배열을 담기 위한 2차원 포인터
} MazeSize;

int Solve(MazeSize* Maze);
int MoveTo(MazeSize* Maze, Position* Current, int Direction);
int GetNextStep(MazeSize* Maze, Position* Current, int Direction, Position* Next);
int GetMaze(char* FilePath, MazeSize* Maze);

#endif
