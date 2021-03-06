// 1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
# define STACK_INIT_SIZE 20
# define STACK_ADD_ELEM 10
typedef struct {
	char * bottom;
	char * top;
	int size;      //size of struct
}sqStruct;

void InitStack(sqStruct * stack)
{
	stack->bottom = (char*)malloc(sizeof(char)*STACK_INIT_SIZE);
	if (!stack->bottom) exit(0);
	stack->top = stack->bottom;
	stack->size = STACK_INIT_SIZE;
}

void PushStack(sqStruct * stack, char x)
{
	if (stack->top - stack->bottom >= stack->size)//overflow
	{
		stack->bottom = (char*)realloc(stack, (stack->size + STACK_ADD_ELEM) * sizeof(char));
		//realloc function: to new address to meet the requirement, the old data will be copy to the new place, realloc return a ptr
		if (!stack) exit(0);
	}
	*(stack->top) = x;
	stack->top++;//top always upper than the storage place
}

char PopStack(sqStruct * stack)
{
	if (stack->bottom == stack->top) return 0;
	stack->top--;
	return *(stack->top);
}

void ClearStack(sqStruct * stack)
{
	stack->top = stack->bottom;
}

int stackLen(sqStruct  stack)
{
	return(stack.top - stack.bottom);
}
using namespace std;
int main()
{
	sqStruct b, o;//b means string for binary, o means string for octonary
	int length = 0;
	char elem;
	InitStack(&b);
	InitStack(&o);
	
	scanf_s("%c", &elem);
	while (elem !='#')
	{
		PushStack(&b, elem);
		length++;//the length of the string is known
		scanf_s("%c", &elem);
	}
	int popT;//pop 3 binary numbers at ones time, clear it be 0 after ones pop
	int sum;// to record the orctonary
	while ((length/3)>=1)
	{
		sum = 0;
		for (popT= 0; popT < 3; popT++)
		{
             elem=PopStack(&b);
			 sum = sum + (elem - '0')*pow(2, popT);
			 length--;
        }
		PushStack(&o, (sum + '0'));
	}
	sum = 0;
	for (popT = 0;length>0;popT++,length--)
	{
		elem = PopStack(&b);
		sum = sum + ( elem- '0')*pow(2, popT);
	}
	PushStack(&o, (sum + '0'));
	length = stackLen(o);
	while (length)
	{
		elem = PopStack(&o);
		cout << elem;
		length--;
	}
	return 0;
}