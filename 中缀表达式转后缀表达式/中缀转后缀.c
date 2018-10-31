#include"中缀转后缀.h"


void MidTurnBack(cell* arr, int sz)
{
	Stack s;
	int i = 0;
	assert(arr);
	StackInit(&s);
	for (; i < sz; i++)
	{
		switch (arr[i].op)
		{
		case Data:
		{
			printf("%d  ", arr[i].data);
			break;
		}
		case Ope:
		{
			if (arr[i].data == '*' || arr[i].data == '/')
			{
				while (StackNum(&s) && (StackTop(&s) == '*' || StackTop(&s) == '/'))
				{
					printf("%c  ", StackTop(&s));
					StackPop(&s);
				}
			}
			else
			{
				while (StackNum(&s) && StackTop(&s) != '(')
				{
						printf("%c  ", StackTop(&s));
						StackPop(&s);
				}
			}
			StackPush(&s, arr[i].data);
			break;
		}
		case Left:
		{
			StackPush(&s, arr[i].data);
			break;
		}
		case Right:
		{
			while (StackTop(&s) != '(')
			{
				printf("%c  ", StackTop(&s));
				StackPop(&s);
			}
			StackPop(&s);
			break;
		}
		}
	}
	while (StackNum(&s))
	{
		printf("%c  ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
}