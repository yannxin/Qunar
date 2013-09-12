
#pragma once

struct personInfo
{
	int income;
	char ID[20];
};

void swap(personInfo &a, personInfo &b);
int leftChild(int i);
int rightChild(int i);
void AdjustHeap(personInfo people[], int low, int high, int i);
void BuildMinHeap(personInfo people[], int low, int high);
void HeapSort(personInfo people[], int low, int high);

