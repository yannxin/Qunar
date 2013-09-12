// RandGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RandGame.h"

#define N 10

int matrix[N][N];

void initMatrix()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			matrix[i][j] = rand()%4;
}

//search by row
int find1(int (*matrix)[10], int x, int y)
{
	int k = 1;
	while(k < 5)
	{
		if (matrix[x][y] != matrix[x][y+k])
		{
			isFound = 0;
			return 0;
		}
	}
	return 1;
}

void print1(int x, int y)
{
	int k = 0;
	while (k < 5)
	{
		printf("(%d,%d) ", x, y+k);
	}
	printf("\n");
}

//search by column
int find2(int (*matrix)[10], int x, int y)
{
	int k = 1;
	while(k < 5)
	{
		if (matrix[x][y] != matrix[x+k][y])
		{
			isFound = 0;
			return 0;
		}
	}
	return 1;
}

void print2(int x, int y)
{
	int k = 0;
	while (k < 5)
	{
		printf("(%d,%d) ", x+k, y);
	}
	printf("\n");
}
//search by diagonal
int find3(int (*matrix)[10], int x, int y)
{
	int k = 1;
	while(k < 5)
	{
		if (matrix[x][y] != matrix[x+k][y+k])
		{
			isFound = 0;
			return 0;
		}
	}
	return 1;
}

void print3(int x, int y)
{
	int k = 0;
	while (k < 5)
	{
		printf("(%d,%d) ", x+k, y+k);
	}
	printf("\n");
}
//search by anti-diagonal
int find4(int (*matrix)[10], int x, int y)
{
	int k = 1;
	while(k < 5)
	{
		if (matrix[x][y] != matrix[x+k][y-k])
		{
			isFound = 0;
			return 0;
		}
	}
	return 1;
}

void print4(int x, int y)
{
	int k = 0;
	while (k < 5)
	{
		printf("(%d,%d) ", x+k, y-k);
	}
	printf("\n");
}



void RandGame1()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j <= N-5; j++)
			if (find1(matrix, i, j))
			{
				print1(i, j);
			}
}

void RandGame2()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j <= N-5; j++)
			if (find2(matrix, j, i))
			{
				print2(j, i);
				return;
			}
}

void RandGame3()
{
	int i, j;
	for (i = 0; i <= N-5; i++)
		for (j = 0; j <= N-5; j++)
			if (find3(matrix, j, i))
			{
				print3(j, i);
				return;
			}
}

void RandGame4()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j <= N-5; j++)
			if (find4(matrix, j, i))
			{
				print4(j, i);
				return;
			}
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

