#pragma once

#include<assert.h>
#include<malloc.h>

//带头节点的单链表
typedef int DataType;

typedef struct SHListNode
{
	struct SHListNode* _pNext;
	DataType _data;
}SHListNode,Node;

void SHListInit(SHListNode** pHead);
void SHListPushBack(SHListNode* pHead, DataType data);
void SHListPopBack(SHListNode* pHead);
void SHListPushFront(SHListNode* pHead, DataType data);
void SHListPopFront(SHListNode* pHead);
void SHListDestroy(SHListNode* pHead);
SHListNode* BuySHListNode(DataType data);
///////////////////////////








