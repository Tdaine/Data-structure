#include"源.h"



void test()
{
//	ListNode* pHead;
	
	//InitLinkList(&pHead);//初始化
	//PushBack(&pHead, 1);//后插
	//PushBack(&pHead, 2);
	//PushBack(&pHead, 3);
	//PushBack(&pHead, 4);
	
	//PrintFromTailToFront(pHead);//从尾到头打印单链表
	//printf("\n");
	//ListNode* pos =  FindPosNode(pHead, 3);
	//InsertPosFront(pos, 6);
	//PrintFromTailToFront(pHead);//从尾到头打印单链表
	//printf("\n");
	//BubbleSort(pHead);
	//QuickSort(pHead);//快速排序
	//ReverseList(&pHead);//逆置单链表
	
	//ListNode* Last = LastNode(pHead);//找最后一个节点
	//Last->next = pHead;
	//Last = TosephCircle(pHead,3);//约瑟夫环
	//
	//DelectListNotTail(pHead);
}


void test1()
{
	ListNode* p1, *p2;
	InitLinkList(&p1);//初始化
	PushBack(&p1, 1);//后插
	PushBack(&p1, 5);
	PushBack(&p1, 7);
	PushBack(&p1, 11);

	InitLinkList(&p2);//初始化
	PushBack(&p2, 2);//后插
	PushBack(&p2, 3);
	PushBack(&p2, 8);
	PushBack(&p2, 10);
	//ListNode* pNewList = NewCombineList(p1, p2);
	ListNode* pNewList = ReNewCombineList(p1, p2);//合并两个链表,,生成第三个链表  递归

	PrintFromTailToFront(pNewList);//从尾到头打印单链表
	printf("\n");
	DelLastNode(pNewList, 3);
	PrintFromTailToFront(pNewList);//从尾到头打印单链表
	//ListNode* Middle = FindMiddleNode(pNewList);//查找单链表的中间节点，只遍历一次链表
	//ListNode* LastNode = FindLastNode(pNewList, 3);//查找的单链表的倒数第K个节点，只遍历一次链表
	
	//printf("%d", LastNode->data);
	printf("\n");
}


test3()
{
	//ListNode* pHead;
	//InitLinkList(&pHead);//初始化
	//PushBack(&pHead, 1);//后插
	//PushBack(&pHead, 2);
	//PushBack(&pHead, 3);
	//PushBack(&pHead, 4);
	//PushBack(&pHead, 5);//后插
	//PushBack(&pHead, 6);
	//PushBack(&pHead, 7);
	//PushBack(&pHead, 8);
	//PushBack(&pHead, 9);
	
	//FindPosNode(pHead, 9)->next = FindPosNode(pHead, 3);//找到指定节点的位置
	//ListNode* pMeetNode = GetMeetNode(pHead);

	//int a = GetCircleLen( pMeetNode);//求环的长度

	//ListNode* EnterNode = GetEnterNode(pHead,pMeetNode);


	ListNode* p1, *p2;
	InitLinkList(&p1);//初始化
	PushBack(&p1, 1);//后插
	PushBack(&p1, 5);
	PushBack(&p1, 7);
	PushBack(&p1, 11);

	InitLinkList(&p2);//初始化
	PushBack(&p2, 2);//后插
	PushBack(&p2, 3);
	PushBack(&p2, 8);
	PushBack(&p2, 10);

	
	printf("\n");
	//FindPosNode(p1, 11)->next = FindPosNode(p2, 3);//找到指定节点的位置
	//FindPosNode(p2, 10)->next = FindPosNode(p2, 3);//构成环
	//int a = IsListCross(p1, p2);//判断两个链表是否相交
	//int a = IsListCrossWithCircle(p1,p2);//判断两个链表是否相交(假设链表带环)


	//ListNode* CrossNode = GetCrossNode(p1,p2);//求交点
}

void ComplexLinkList_test()
{
	Node node1, node2, node3, node4;
	node4.data = 4;
	node4.pNext = NULL;
	node4.pRandom = NULL;

	node3.data = 3;
	node3.pNext = &node4;
	node3.pRandom = &node3;

	node2.data = 2;
	node2.pNext = &node3;
	node2.pRandom = &node1;


	node1.data = 1;
	node1.pNext = &node2;
	node1.pRandom = &node3;

	

	Node* ret = CopyComplexLinkList(&node1);

}

int main()
{
	//test();
	//test1();
	//test3();
	ComplexLinkList_test();
	system("pause");
	return 0;
}