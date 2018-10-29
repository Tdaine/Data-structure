#include<assert.h>
#include<malloc.h>
#include<stdio.h>


typedef int DataType;
typedef struct LinkList
{
	struct LinkList* next;
	DataType data;
}ListNode;

typedef struct ListNode
{
	struct ListNode* pNext;
	struct ListNode* pRandom;
	DataType data;
}Node;

void InitLinkList(ListNode** pplist);//初始化
void PushBack(ListNode** pplist, DataType data);//后插
ListNode* BuyNode(DataType data);
void PrintFromTailToFront(ListNode* pHead);//从尾到头打印单链表
void DelectListNotTail(ListNode* pHead);//删除一个无头单链表的非尾节点（不能遍历链表）
ListNode* FindPosNode(ListNode* pHead,DataType pos);//找到指定节点的位置
void InsertPosFront(ListNode* pos, DataType data);//在无头单链表的一个节点前插入一个节点（不能遍历链表）
ListNode* LastNode(ListNode* pHead);//找最后一个节点
ListNode* TosephCircle(ListNode* pHead, int m);//约瑟夫环
void ReverseList(ListNode** pHead);//逆置单链表
void BubbleSort(ListNode* pHead);//冒泡排序
void QuickSort(ListNode* pHead);//快速排序
void CombineList(ListNode** p1, ListNode* p2);//合并两个链表
ListNode* NewCombineList(ListNode* p1, ListNode* p2);//合并两个链表,,生成第三个链表  非递归
ListNode* ReNewCombineList(ListNode* p1, ListNode* p2);//合并两个链表,,生成第三个链表  递归
ListNode* FindMiddleNode(ListNode* p1);//查找单链表的中间节点，只遍历一次链表
ListNode* FindLastNode(ListNode* p1, int k);//查找的单链表的倒数第K个节点，只遍历一次链表
void DelLastNode(ListNode* p1, int k);//删除单链表的倒数第K个节点

int HasListCircle(ListNode* pHead);//判断链表是否有环
int GetCircleLen(ListNode* pMeetNode);//求环的长度
ListNode* GetEnterNode(ListNode* pHead, ListNode* pMeetNode);//求环的入口
int IsListCross(ListNode* p1, ListNode* p2);//判断两个链表是否相交(假设链表不带环)
ListNode* GetCrossNode(ListNode* p1, ListNode* p2);//求交点(假设链表不带环)
int IsListCrossWithCircle(ListNode* p1, ListNode* p2);//判断两个链表是否相交(假设链表带环)
Node* CopyComplexLinkList(Node* p1);//复制复杂链表
