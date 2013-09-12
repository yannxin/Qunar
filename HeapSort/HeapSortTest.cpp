// HeapSortTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HeapSort.h"

#define N 10000
#define M 100
struct personInfo people[N];

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		people[i].income = rand()%100000;
		itoa(rand()%100000, people[i].ID, 10);
	}
	BuildMinHeap(people, 0, M-1);
	for (i = M; i < N; i++)
	{
		if (people[i].income > people[0].income)
		{
			people[0].income = people[i].income;
			strcpy(people[0].ID, people[i].ID);
			AdjustHeap(people, 0, M-1, 0);
		}
	}

	HeapSort(people, 0, M-1);

	for (i = 0; i < M-1; i++)
	{
		printf("%d: %d %s\n", i+1, people[i].income, people[i].ID);
	}
	return 0;
}

