// HeapSort.cpp

#include "stdafx.h"
#include "HeapSort.h"

void swap(personInfo &a, personInfo &b)
{
	personInfo temp(a);

	a.income = b.income;
	strcpy(a.ID, b.ID);

	b.income = temp.income;
	strcpy(b.ID, temp.ID);
}

int leftChild(int i)
{
    return (2 * i + 1);
}

int rightChild(int i)
{
    return (2 * i + 2);
}

void AdjustHeap(personInfo people[], int low, int high, int i)
{
	int left = leftChild(i);
	int right = rightChild(i);
	int k = i; // the largest
	while (left <= high || right <= high)
	{
		if (left <= high && people[left].income < people[k].income)
			k = left;
		if (right <= high && people[right].income < people[k].income)
			k = right;

		if (k != i)
		{
			swap(people[i], people[k]);
			i = k;
			left = leftChild(i);
			right = rightChild(i);
		}
		else
		{
			break;
		}
	}
}

void BuildMinHeap(personInfo people[], int low, int high)
{
	int p = low + (high - low + 1) / 2 - 1;
	for (; p >= low; p--)
	{
		AdjustHeap(people, low, high, p);
	}
}

void HeapSort(personInfo people[], int low, int high)
{
	BuildMinHeap(people, low, high);

	int i;
	for (i = high; i > low; i--)
	{
		swap(people[low], people[i]);
		AdjustHeap(people, low, i-1, low);
	}
}