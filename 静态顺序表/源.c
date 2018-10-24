////初始化 
//void InitSeqList(PSeqList pSeq);
////尾部插入 
//void PushBack(PSeqList pSeq, DataType data);
////尾部删除 
//void PopBack(PSeqList pSeq);
////头部插入 
//void PushFront(PSeqList pSeq, DataType data);
////头部删除 
//void PopFront(PSeqList pSeq);
////查找指定元素 
//int Find(PSeqList pSeq, DataType data);
////指定位置插入 
//void Insert(PSeqList pSeq, int pos, DataType data);
////删除指定位置元素 
//void Erase(PSeqList pSeq, int pos);
////删除指定元素 
//void Remove(PSeqList pSeq, DataType data);

////删除所有的指定元素 
//void RemoveAll(PSeqList pSeq, DataType data);
////返回顺序表的大小 
//int Size(PSeqList pSeq);
////判断顺序表是否为空 
//int Empty(PSeqList pSeq);
////冒泡排序 
//void BubbleSort(PSeqList pSeq);
////选择排序 
//void SelectSort(PSeqList pSeq);
////选择排序的优化 
//void SelectSortOP(PSeqList pSeq);
////二分查找 
//int BinarySearch(PSeqList pSeq, DataType data);
////二分查找递归写法 
//int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);
//
////打印 
//void PrintSeqList(PSeqList pSeq);

#include "SeqList.h"

void test()
{
	SeqList pSeq;
	InitSeqList(&pSeq);
	PushBack(&pSeq, 1);
	PushBack(&pSeq, 2);
	PushBack(&pSeq, 3);
	PushBack(&pSeq, 4);
	PushBack(&pSeq, 0);
	/*PushFront(&pSeq, 1);
	PushFront(&pSeq, 2);
	PushFront(&pSeq, 3);
	PushFront(&pSeq, 4);
	PushFront(&pSeq, 5);
	PushFront(&pSeq, 1);*/
	PrintSeqList(&pSeq);
	//PopBack(&pSeq);
	//PopFront(&pSeq);
	//PrintSeqList(&pSeq);

	/*int t = Find(&pSeq, 4);
	if (t == -1)
	{
		printf("没有这个数\n");
	}
	else
		printf("坐标为：%d\n", t);
		*/

	/*Insert(&pSeq,3, 7);
	PrintSeqList(&pSeq);
	Erase(&pSeq, 3);
	PrintSeqList(&pSeq);*/
	/*Remove(&pSeq, 3);
	PrintSeqList(&pSeq);*/
	/*RemoveAll(&pSeq,1);
	PrintSeqList(&pSeq);
	int sz = Size(&pSeq);
	printf("大小为%d字节\n", sz);*/
	/*int ret = Empty(&pSeq);
	if (ret == 0)
	{
		printf("顺序表为空\n");
	}
	else
		printf("顺序表不为空\n");*/
	//BubbleSort(&pSeq);
	//SelectSort(&pSeq);
	//PrintSeqList(&pSeq);
	SelectSortOP(&pSeq);
	PrintSeqList(&pSeq);
	//int pos = BinarySearch(&pSeq,3);
	/*int pos = BinarySearch_R(&pSeq,0 ,pSeq.sz-1,3);
	if (pos == -1)
	{
		printf("没有这个数\n");
	}
	else
		printf("坐标为%d\n", pos);*/
}
 

int main()
{
	test();
	system("pause");
	return;
}