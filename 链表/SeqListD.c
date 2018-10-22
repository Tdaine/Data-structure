#include"SeqListD.h"

void InitSeqList(pSeqList pSeq)//初始化
{
	assert(pSeq != NULL);
	pSeq->data = (DataType*)calloc(COUNT, sizeof(DataType));
	if (pSeq->data == NULL)
	{
		perror("InitSeqList::use calloc");
		exit(EXIT_FAILURE);
	}
	pSeq->sz = 0;
	pSeq->capacity = COUNT;
}