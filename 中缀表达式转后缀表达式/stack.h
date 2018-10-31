
#pragma once

#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 10
typedef char DataType;
typedef struct Stack
{
	int top;
	DataType stack[max];
}Stack;

enum {Data,Ope,Left,Right} operate;

typedef struct Cell
{
	enum operate op;
	int data;
}cell;


void StackInit(Stack* p);
void StackPush(Stack* p,DataType data);
int StackPop(Stack* p);

void MatchBrackets(char* array, int sz);
int CalRPN(cell* RPN, int sz);