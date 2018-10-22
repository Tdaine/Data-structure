#ifndef __SEQLISTD_H__
#define __SEQLISTD_H__

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<assert.h>

#define COUNT 6
typedef int DataType;
typedef struct SeqList
{
	DataType *data;
	int sz;//现存元素个数
	int capacity;//容量
}SeqList,*pSeqList;
void InitSeqList(pSeqList pSeq);


#endif //__SEQLISTD_H__