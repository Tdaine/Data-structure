#pragma once
#include<assert.h>
#include<stdio.h>

#define NULL 0
typedef int  QDataType;

typedef struct LinkList
{
	struct LinkList* next;
	QDataType data;
}QLinkList;

typedef struct Queue
{
	QLinkList* front;
	QLinkList* rear;
	int sz;
}Queue;


void QueueInit(Queue* Qlist);
void QueuePush(Queue* Qlist,QDataType data);
void QueuePop(Queue* Qlist);
QDataType QueueFront(Queue* Qlist);
QDataType QueueBack(Queue* Qlist);
int QueueSize(Queue* Qlist);
int QueueEmpty(Queue* Qlist);