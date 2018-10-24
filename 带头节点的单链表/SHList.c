#include"SHList.h"

SHListNode* BuySHListNode(DataType data)
{
	SHListNode* pNewNode = (SHListNode*)malloc(sizeof(SHListNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void SHListInit(SHListNode** pHead)//头节点
{
	assert(pHead);
	*pHead = BuySHListNode(0);

}

void SHListPushBack(SHListNode* pHead, DataType data)//尾插
{
	Node* pTailNode = pHead;
	assert(pHead);
	while (pTailNode->_pNext)
	{
		pTailNode = pTailNode->_pNext;
	}
	pTailNode->_pNext = BuySHListNode(data);

}


//空链表:pHead->头节点：->NULL
//非空链表
void SHListPopBack(SHListNode* pHead)//尾删
{
	Node* pTailNode = pHead;
	Node* pre = NULL;
	assert(pHead);
	if (NULL == pHead->_pNext)
	{
		return 0;
	}
	while (pTailNode->_pNext)
	{
		pre = pTailNode;
		pTailNode = pTailNode->_pNext;
	}
	pre->_pNext = NULL;
	free(pTailNode);
	pTailNode = NULL;
}


void SHListPushFront(SHListNode* pHead, DataType data)//头插
{
	Node* pNewNode = NULL;
	assert(pHead);
	pNewNode = BuySHListNode(data);
	if (pNewNode != NULL)
	{
		pNewNode->_pNext = pHead->_pNext;
		pHead->_pNext = pNewNode;
	}
}

void SHListPopFront(SHListNode* pHead)
{
	Node* pDelNode = NULL;
	assert(pHead);
	if (NULL == pHead->_pNext)
	{
		return;
	}
	pDelNode = pHead->_pNext;
	pHead->_pNext = pDelNode->_pNext;
	free(pDelNode);
	pDelNode = NULL;
}

void Test()
{
	SHListNode* pHead = NULL;
	SHListInit(&pHead);
	SHListPushBack(pHead, 1);
	SHListPushBack(pHead, 2);
	SHListPushBack(pHead, 3);
	SHListPushBack(pHead, 4);
	SHListPopBack(pHead);
	/*SHListPushFront(pHead, 1);
	SHListPushFront(pHead, 2);
	SHListPushFront(pHead, 3);
	SHListPushFront(pHead, 4);*/
	SHListPopFront(pHead);
}

int main()
{
	Test();
	return 0;
}