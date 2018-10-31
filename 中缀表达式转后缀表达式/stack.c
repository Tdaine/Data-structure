#include"stack.h"

void StackInit(Stack* p)
{
	assert(p);
	p->top = 0;
}
void StackPush(Stack* p, DataType data)
{
	assert(p);
	if (p->top <= max)
	{
		p->stack[p->top] = data;
		p->top++;
	}
	else
	{
		printf("stack full\n");
	}
}
int StackPop(Stack* p)
{
	//int ch;
	assert(p);
	if (p->top != 0)
	{
		p->top--;
		//ch = p->stack[p->top];
		return p->stack[p->top];
	}

}



int StackNum(Stack* p)
{
	assert(p);
	return p->top;
}

int StackTop(Stack* p)
{
	int n;
	assert(p);
	if(p->top)
	{
		n = p->top;
		return p->stack[n-1];
	}
	
	return 0;
}

int IsBrackets(DataType data)
{
	if (')' == data || ']' == data || '}' == data || '(' == data || '[' == data || '{' == data)
		return 1;
	return 0;
}

void MatchBrackets(char* array, int sz)//括号匹配
{
	int i = 0;
	Stack s;
	assert(array);
	StackInit(&s);
	for (; i < sz; i++)
	{
		if (IsBrackets(array[i]))//判断是否是括号
		{
			if (('(' == array[i]) || ('[' == array[i]) || ('{' == array[i]))//左括号
			{
				StackPush(&s, array[i]);
				continue;
			}
			else //右括号
			{
				if (StackNum(&s))  //栈是否为空
				{
					DataType ch = StackTop(&s);
					if (('(' == ch && ')' == array[i]) ||
						('[' == ch && ']' == array[i]) ||
						('{' == ch && '}' == array[i]))
					{
						StackPop(&s);
						continue;
					}
					else
					{
						printf("匹配失败\n");
						return ;
					}
				}
				printf("右括号比左括号多\n");
				return;
			}
		}
	}
	if (StackNum(&s))
		printf("左括号比右括号多\n");
	else
		printf("匹配成功\n");
}

//int CalRPN(cell* RPN, int sz)//逆波兰表达式（后缀表达式）
//{
//	int i = 0;
//	Stack s;
//	assert(RPN);
//	StackInit(&s);
//	for (; i < sz; i++)
//	{
//		int left = 0;
//		int right = 0;
//		switch (RPN[i].op)
//		{
//		case Data:
//			StackPush(&s, RPN[i].data);
//			break;
//		case Add:
//			right = StackPop(&s);
//			left = StackPop(&s);
//			StackPush(&s, right + left);
//			break;
//		case Sub:
//			right = StackPop(&s);
//			left = StackPop(&s);
//			StackPush(&s, left - right);
//			break;
//		case Mul:
//			right = StackPop(&s);
//			left = StackPop(&s);
//			StackPush(&s, left * right);
//			break;
//		case Div:
//			right = StackPop(&s);
//			left = StackPop(&s);
//			if (0 == right)
//				printf("除数非法\n");
//			else
//				StackPush(&s, left / right);
//			break;
//		}
//	}
//	return StackTop(&s);
//}