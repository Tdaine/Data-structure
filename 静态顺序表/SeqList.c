#include "SeqList.h"

void InitSeqList(pSeqList pSeq)
{
	assert(pSeq);
	memset(pSeq->data, 0, sizeof(DataType)*MAX);
	pSeq->sz = 0;
}

void PushBack(pSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("空间已满\n");
		return 0;
	}
	pSeq->data[pSeq->sz] = data;
	pSeq->sz++;
}

void PrintSeqList(pSeqList pSeq)
{
	assert(pSeq);
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d->", pSeq->data[i]);
	}
	printf("NULL\n");
}

void PopBack(pSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	pSeq->sz--;
}

void PushFront(pSeqList pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满\n");
		return;
	}
	int i = 0;
	for (i = pSeq->sz-1; i >= 0; i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[0] = data;
	pSeq->sz++;
}

void PopFront(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

int Find(pSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == data)
			return i;
	}
	return -1;

}

void Insert(pSeqList pSeq, int pos, DataType data)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满\n");
		return;
	}
	for (i = pSeq->sz - 1; i >= pos - 1; i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[pos - 1] = data;
	pSeq->sz++;
}

void Erase(pSeqList pSeq, int pos)
{
	int i = 0;
	assert(pSeq);
	for (i = pos - 1; i < pSeq->sz-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

void Remove(pSeqList pSeq, DataType data)
{
	int i;
	assert(pSeq);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == data)
			break;
	}
	for (; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

void RemoveAll(pSeqList pSeq, DataType data)
{
	int i;
	int count = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz; i++)
	{

		if (pSeq->data[i] != data)
		{
			pSeq->data[count++] = pSeq->data[i];
		}
	}
	pSeq->sz = count;
}

int Size(pSeqList pSeq)
{
	assert(pSeq);
	return (pSeq->sz*sizeof(DataType));
}

int Empty(pSeqList pSeq)
{
	assert(pSeq);
	return pSeq->sz;
}

void swap(DataType *p1,DataType *p2)
{
	DataType tmp;
	tmp = *p2;
	*p2 = *p1;
	*p1 = tmp;
}

void BubbleSort(pSeqList pSeq)
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz-1; i++)
	{
		for (j = 0; j < pSeq->sz - 1 - i;j++)
		{
			if (pSeq->data[j] < pSeq->data[j + 1])
			{
				swap(pSeq->data + j, pSeq->data + j + 1);
			}
		}

	}
}

void SelectSort(pSeqList pSeq)
{
	assert(pSeq);
	int i = 0;
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		int m = 0;
		int j = 0;
		for (j = 1; j < pSeq->sz - i; j++)
		{
			if (pSeq->data[m] > pSeq->data[j])
				m = j;

		}
		swap(pSeq->data + m, pSeq->data+pSeq->sz - 1 - i);
	}

}

void SelectSortOP(pSeqList pSeq)
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	int start = 0;
	int end = pSeq->sz-1;
	while (start < end)
	{
		int maxpos = start;
		int minpos = start;
		i = start;
		for (; i < end; i++)
		{
			if (pSeq->data[maxpos] < pSeq->data[i + 1])
				maxpos = i + 1;
			if (pSeq->data[minpos] > pSeq->data[i + 1])
				minpos = i + 1;
		}
		/*swap(pSeq->data + maxpos, pSeq->data + end);
		if (maxpos != start || minpos != end)
		{
			if (minpos == end)
			{
				minpos == maxpos;
				swap(pSeq->data + minpos, pSeq->data + start);
			}
			else
				swap(pSeq->data + minpos, pSeq->data + start);
		}*/
		if (minpos != start)
		{
			swap(pSeq->data + minpos, pSeq->data + start);
		}
		if (maxpos == start)
		{
			maxpos = minpos;
		}
		if(maxpos!=end)
		{
			swap(pSeq->data + maxpos, pSeq->data + end);
		}
			start++;
			end--;
	}
}

int BinarySearch(pSeqList pSeq, DataType data)
{
	assert(pSeq);
	int left = 0;
	int right = pSeq->sz - 1;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (pSeq->data[mid] > data)
		{
			right = mid;
			left;
		}
		else if (pSeq->data[mid] < data)
		{
			left = mid;
			right;
		}
		else
			return mid;
	}
	return -1;
}

int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d)
{
	assert(pSeq);
	if (left > right)
		return-1;
	int mid = left + (right - left) / 2;
	if (pSeq->data[mid] > d)
		BinarySearch_R(pSeq, left, mid, d);
	else if (pSeq->data[mid] < d)
		BinarySearch_R(pSeq, mid, right, d);
	else
		return mid;
}