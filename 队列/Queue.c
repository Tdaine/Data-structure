#include"Queue.h"
void QueueInit(Queue* Qlist)//初始化队列，无头节点
{
	assert(Qlist);
	Qlist->front = NULL;//为什么初始化不能是Qlist = NULL,初始化不用传二级指针吗？为什么链表初始化要传二级指针
	Qlist->rear = NULL;//不可以这样初始化,因为他是结构体类型已经有了空间，所以不需要初始化分配空间    因为这个定义的不是指针，传一级指针已经达到了取外部变量地址的目的，改变内部形参就可以改变实参，
	Qlist->sz = 0;                                                              //在链表中，定义的就是指针类型，所以为了改变外部指针只能传递二级指针
}

QLinkList* BuyNewNode(QDataType data)
{
	QLinkList *NewNode = (QLinkList*)malloc(sizeof(QLinkList));
	if (NewNode)
	{
		NewNode->data = data;
		NewNode->next = NULL;
		return NewNode;
	}
	perror("buy new node");
	return 0;
}

void QueuePush(Queue* Qlist,QDataType data)
{
	//Queue* Cur;
	QLinkList* NewNode = NULL;
	assert(Qlist);
	NewNode = BuyNewNode(data);
	if (Qlist ->front == NULL)
	{
		Qlist->front = NewNode;
		Qlist->rear = NewNode;
	}
	else
	{
		/*Cur = Qlist;//为什么不能进行遍历，，因为要使用节点类型的指针才能遍历
		while (Cur->front->next)
		{
			Cur->front = Cur->front->next;
		}
		Cur->front->next = NewNode;*/
		 Qlist->rear->next  = NewNode;
		 Qlist->rear = NewNode;
	}
	Qlist->sz++;
}
void QueuePop(Queue* Qlist)
{
	assert(Qlist);
	if(Qlist->front)
	{
		if (Qlist->front->next)
		{
			Qlist->front = Qlist->front->next;
		}
		else
			Qlist->front = Qlist->rear = NULL;
		Qlist->sz--;
	}
	
}
QDataType QueueFront(Queue* Qlist)
{
	assert(Qlist);
	if (Qlist->front)
		return Qlist->front->data;
}
QDataType QueueBack(Queue* Qlist)
{
	assert(Qlist);
	if (Qlist->front)
		return Qlist->rear->data;
}
int QueueSize(Queue* Qlist)
{
	assert(Qlist);
	return Qlist->sz;
}
int QueueEmpty(Queue* Qlist)
{
	assert(Qlist);
	return !(Qlist->sz);
}