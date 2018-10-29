#include"源.h"

void InitLinkList(ListNode** pplist)//初始化
{
	assert(pplist);
	*pplist = NULL;
}
//void PushBack(ListNode** pplist, DataType data)//后插
//{
//	ListNode* pNewNode = NULL;
//	ListNode* pCur = *pplist;
//	assert(pplist);
//	while (pCur)
//		pCur = (pCur)->next;
//	pNewNode = BuyNode(data);
//	pCur = pNewNode;//不能给空指针直接指向一个节点
//}

ListNode* BuyNode(DataType data)
{
	ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
	if (pNewNode == NULL)
	{
		perror("buy node::error");
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;
}


void PushBack(ListNode** pplist, DataType d)//后插
{
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		ListNode* newnode = BuyNode(d);
		if (newnode == NULL)
			return;
		*pplist = newnode;
	}
	else
	{
		ListNode* cur = *pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = BuyNode(d);
	}
}


void PrintFromTailToFront(ListNode* pHead)//从尾到头打印单链表
{
	//assert(pHead);
	if (pHead)
	{
		PrintFromTailToFront(pHead->next);
		printf("%d ", pHead->data);
	}
}

void DelectListNotTail(ListNode* pHead)//删除一个无头单链表的非尾节点
{
	ListNode* pDel = NULL;
	while (pHead && pHead->next)
	{
		pDel = pHead->next;
		pHead->data = pDel->data;
		pHead->next = pDel->next;
		free(pDel);
	}
}

ListNode* FindPosNode(ListNode* pHead, DataType pos)//找到指定节点的位置
{
	assert(pHead);
	while (pHead->data != pos)
	{
		pHead = pHead->next;
	}
	return pHead;
}

void InsertPosFront(ListNode* pos, DataType data)//在无头单链表的一个节点前插入一个节点（不能遍历链表）
{
	ListNode* NewNode = NULL;
	NewNode = BuyNode(pos->data);
	NewNode->next = pos->next;
	pos->next = NewNode;
	pos->data = data;
}

ListNode* LastNode(ListNode* pHead)//找最后一个节点
{
	//ListNode* Last;
	assert(pHead);
	while (pHead->next)
	{
		pHead = pHead->next;
	}
	return pHead;
}
ListNode* TosephCircle(ListNode* pHead,int m)//约瑟夫环
{
	int count = 0;
	ListNode* Del = NULL;
	while (pHead->next != pHead)
	{
		count = m;
		while (--count)
		{
			pHead = pHead->next;
		}
		Del = pHead->next;
		pHead->data = Del->data;
		pHead->next = Del->next;
		free(Del);
	}
	pHead->next = NULL;
	return pHead;
}


void ReverseList(ListNode** pHead)//逆置单链表
{
	ListNode* pNext = NULL;
	ListNode* pCur = NULL;
	ListNode* pNew = NULL;
	pCur = *pHead;
	while (pCur)
	{
		pNext = pCur->next;
		pCur->next = pNew;
		pNew = pCur;
		pCur = pNext;
	}
	*pHead = pNew;
}

void BubbleSort(ListNode* pHead)//冒泡排序  大到小
{
	ListNode* Next = NULL;
	ListNode* Cur = NULL;
	ListNode* pTail = NULL;
	int flag = 0;

	if (pHead == NULL || pHead->next == NULL)
		return;
	Cur = pHead;
	while (Cur != pTail)
	{
		flag = 0;
		while (Cur->next != pTail)
		{
			Next = Cur->next;
			if (Cur->data < Next->data)
			{
				DataType tmp = Cur->data;
				Cur->data = Next->data;
				Next->data = tmp;
				flag = 1;
			}
			Cur = Next;
			
		}
		if (flag == 0)
		{
			return;
		}
		pTail = Next;
		Cur = pHead;
	}
}

void QuickSort(ListNode* pHead)//快速排序
{
	ListNode* left = NULL;
	ListNode* right = NULL;
	ListNode* cur = NULL;
	int flag = 0;

	if (pHead == NULL || pHead->next == NULL)
		return;
	cur = pHead;
	left = pHead;

	while (cur->next != right && cur != right)
	{
		DataType max = left->data;
		DataType min = left->data;
		cur = left;
		while (cur->next != right)
		{
			cur = cur->next;
			if (max < cur->data)
			{
				max = cur->data;
				flag = 1;
			}
			if (min > cur->data)
			{
				min = cur->data;
			}
		}
		if (flag == 0)
			return;
		right = cur;
		left->data = max;
		right->data = min;
		cur = left;
		left = left->next;  
	}
}

void CombineList(ListNode** p1,ListNode* p2)//合并链表p1,p2 到p1
{
	if (*p1 == NULL)
	{
		*p1 = p2;
		return;
	}
	if (p2 == NULL)
	{
		return;
	}
	ListNode* cur1 = NULL;
	ListNode* pre1 = NULL;
	ListNode* cur2 = NULL;
	ListNode* pre2 = NULL;
	ListNode* now = NULL;
	cur1 = *p1;
	pre1 = cur1;
	cur2 = p2;
	if (cur2->data <= cur1->data)//从小到大排序
	{
		pre2 = cur2->next;
		cur2->next = cur1;
		cur1 = cur2;
		pre1 = cur1->next;
		cur2 = pre2;
	}
	else
	{
		now = pre1;
		pre1 = cur1->next;
	}
	while (pre1&&cur2)
	{
		
		if (cur2->data <= pre1->data)//从小到大排序
		{
			pre2 = cur2->next;
			cur2->next = pre1;
			now->next = cur2;
			now = now->next;
			cur2 = pre2;
		}
		else
		{
			now = pre1;
			pre1 = pre1->next;
		}
	}
	if (pre1 == NULL)
	{
		pre1 = pre2;
	}
}

ListNode* NewCombineList(ListNode* p1, ListNode* p2)//合并两个链表,,生成第三个链表  非递归
{
	ListNode* pNewList = NULL;
	ListNode* p3 = NULL;
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	if (p1->data < p2->data)
	{
		pNewList = p3 = p1;
		p1 = p1->next;
	}
	else
	{
		pNewList = p3 = p2;
		p2 = p2->next;
	}
	while (p1&&p2)
	{
		if (p1->data < p2->data)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
		else
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	if (p1 == NULL)
		p3 = p2;
	if (p2 == NULL)
		p3 = p1;
	return pNewList;
}

ListNode* ReNewCombineList(ListNode* p1, ListNode* p2)//合并两个链表,,生成第三个链表  递归
{
	ListNode* pNewList = NULL;
	//ListNode* p3 = NULL;
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	if (p1->data < p2->data)
	{
		pNewList = p1;
		pNewList->next = ReNewCombineList(p1->next, p2);
	}
	else
	{
		pNewList = p2;
		pNewList->next = ReNewCombineList(p1, p2->next);
	}
	return pNewList;
}

ListNode* FindMiddleNode(ListNode* p1)//查找单链表的中间节点，只遍历一次链表
{
	ListNode* pFast = p1;
	ListNode* pSlow = p1;
	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

ListNode* FindLastNode(ListNode* p1, int k)//查找的单链表的倒数第K个节点，只遍历一次链表
{
	ListNode* pFast = p1;
	ListNode* pSlow = p1;
	if (p1 == NULL || k < 0)
	{
		return NULL;
	}
	while (k--)
	{
		if (pFast == NULL)
			return NULL;
		pFast = pFast->next;
	}
	while (pFast)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

void DelLastNode(ListNode* p1, int k)//删除单链表的倒数第K个节点
{
	ListNode* pFast = p1;
	ListNode* pSlow = p1;
	ListNode* Del = NULL;
	int flag = 0;
	if (p1 == NULL || k < 0)
	{
		return NULL;
	}
	while (k--)
	{
		if (pFast == NULL)
			return NULL;
		pFast = pFast->next;
	}
	while (pFast)
	{
		if (flag++ != 0)
		{
			pSlow = pSlow->next;
		}
		pFast = pFast->next;
	}
	Del = pSlow->next;
	pSlow->next = pSlow->next->next;
	free(Del);
	Del = NULL;
}

int HasListCircle(ListNode* pHead)//判断链表是否有环
{
	assert(pHead);
	ListNode* pFast = pHead;
	ListNode* pSlow = pHead;
	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		if (pFast == pSlow)
			return 1;
	}
	return 0;

}

ListNode* GetMeetNode(ListNode* pHead)//求相遇点
{
	assert(pHead);
	ListNode* pFast = pHead;
	ListNode* pSlow = pHead;
	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		if (pFast == pSlow)
			return pFast;
	}
	return NULL;

}

int GetCircleLen(ListNode* pMeetNode)//求环的长度
{
	ListNode* pCur = pMeetNode;
	int count = 1;
	if (pMeetNode == NULL)
		return 0;
	while (pCur->next != pMeetNode)
	{
		pCur = pCur->next;
		count++;
	}
	return count;
}

ListNode* GetEnterNode(ListNode* pHead, ListNode* pMeetNode)//求环的入口
{
	if (pHead == NULL || pMeetNode == NULL)
		return NULL;
	ListNode* pH = pHead;
	ListNode* pM = pMeetNode;
	while (pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pH;
}

int IsListCross(ListNode* p1, ListNode* p2)//判断两个链表是否相交
{
	assert(p1);
	assert(p2);
	while (p1->next)
	{
		p1 = p1->next;
	}
	while (p2->next)
	{
		p2 = p2->next;
	}
	if (p1 == p2)
		return 1;
	else
		return 0;
}

ListNode* GetCrossNode(ListNode* p1, ListNode* p2)//求交点
{
	assert(p1);
	assert(p2);
	ListNode* Cur1 = p1;
	ListNode* Cur2 = p2;
	int len1 = 0;
	int len2 = 0;
	int sub = 0;
	while (Cur1)
	{
		Cur1 = Cur1->next;
		len1++;
	}
	while (Cur2)
	{
		Cur2 = Cur2->next;
		len2++;
	}
	sub = len1 - len2;
	Cur1 = p1;
	Cur2 = p2;
	if (sub > 0)
	{
		while (sub--)
			p1 = p1->next;
	}
	else if(sub < 0)
	{
		while (sub++)
			p2 = p2->next;
	}

	while (p1 && p2)
	{
		p1 = p2->next;
		p2 = p2->next;
		if (p1 == p2)
			return p1;
	}
	return NULL;
}

int IsListCrossWithCircle(ListNode* p1, ListNode* p2)//判断两个链表是否相交(假设链表带环)
{
	if (p1 == NULL || p2 == NULL)
		return 0;
	if (0 == HasListCircle(p1) && 0 == HasListCircle(p2))
	{
		ListNode* pTailNode1 = p1;
		ListNode* pTailNode2 = p2;
		while (pTailNode1->next)
			pTailNode1 = pTailNode1->next;
		while (pTailNode2->next)
			pTailNode2 = pTailNode2->next;
		if (pTailNode1 = pTailNode2)
			return 1;
	}
	else if (HasListCircle(p1) && HasListCircle(p2))
	{
		ListNode* pMeetNode1 = GetMeetNode(p1);
		ListNode* pMeetNode2 = GetMeetNode(p2);
		ListNode* pCur = pMeetNode1;
		while (pCur->next != pMeetNode1)
		{
			if (pCur == pMeetNode2)
				return 2;
			pCur = pCur->next;
		}
		if (pCur == pMeetNode2)
		{
			return 2;
		}
	}
	return 0;
}

Node* BuyNode1(DataType d)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode)
	{
		NewNode->data = d;
		NewNode->pNext = NULL;
		NewNode->pRandom = NULL;
		return NewNode;
	}
	else
	{
		perror("malloc::BuyNode");
		return NULL;
	}
}

Node* CopyComplexLinkList(Node* p1)//复制复杂链表
{
	Node* pPre = p1;
	Node* NewNode = NULL;
	Node* pCur = NULL;
	//在原链表每个节点后与此节点相同的新节点
	while (pPre)
	{
		NewNode = BuyNode1(pPre->data);
		NewNode->pNext = pPre->pNext;
		pPre->pNext = NewNode;
		pPre = NewNode->pNext;
	}
	//给新结点随机指针域赋值
	pPre = p1;
	while (pPre)
	{
		pCur = pPre->pNext;
		if (NULL == pPre->pRandom)
			pCur->pRandom = NULL;
		else
			pCur->pRandom = pPre->pRandom->pNext;
		pPre = pCur->pNext;
	}
	//将新结点拆下来
	pPre = p1;
	Node* pPre2 = pPre->pNext;
	pCur = pPre->pNext;
	while (pCur->pNext)
	{
		pPre->pNext = pCur->pNext;
		pPre = pCur->pNext;
		pCur->pNext = pPre->pNext;
		pCur = pCur->pNext;
	}
	return pPre2;
}