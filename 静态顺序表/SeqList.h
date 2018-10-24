#ifndef __SeqList_h_
#define __SeqList_h_

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>

typedef int DataType;
#define MAX 10
typedef struct SeqList
{
	DataType data[MAX];
	int sz;
}SeqList,*pSeqList;

void InitSeqList(pSeqList pSeq);
void PushBack(pSeqList pSeq, DataType data);
void PrintSeqList(pSeqList pSeq);
void PopBack(pSeqList pSeq);
void PushFront(pSeqList pSeq, DataType data);
void PopFront(pSeqList pSeq);
int Find(pSeqList pSeq, DataType data);
void Insert(pSeqList pSeq, int pos, DataType data);
void Erase(pSeqList pSeq, int pos);
void Remove(pSeqList pSeq, DataType data);
void RemoveAll(pSeqList pSeq,DataType data);
int Size(pSeqList pSeq);
int Empty(pSeqList pSeq);
void BubbleSort(pSeqList pSeq);
void SelectSort(pSeqList pSeq);
void SelectSortOP(pSeqList pSeq);
int BinarySearch(pSeqList pSeq, DataType data);
int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);

#endif
