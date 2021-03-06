// 2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdio.h>
#include "pch.h"
#include <iostream>
#define MAX_SIZE 20
typedef struct {
	char * base;
	int front;
	int rear;
}SqQueue;
void InitQueue(SqQueue &Q)
{
	Q.base = (char *)malloc(sizeof(char)*MAX_SIZE);
	if (!Q.base) exit(-1);
	Q.front = Q.rear = 0;
}
int LenQueue(const SqQueue Q)
{
	return (Q.rear - Q.front);
}
void InstQueue(SqQueue &Q,char elem)
{
	Q.base[Q.rear] = elem;
	Q.rear++;
}
char DeQueue(SqQueue &Q)
{
	char elem;
	elem = Q.base[Q.front];
	Q.front++;
	return elem;
}
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

void PushStack(sqStruct* stack, char x)
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

int main()
{
	SqQueue Q;
	sqStruct S;
	InitQueue(Q);
	InitStack(&S);
	char element;
	int length = 0;
	scanf_s("%c", &element);
	while (element != '#')
	{
		PushStack(&S, element);
		InstQueue(Q, element);
		length++;
		scanf_s("%c", &element);
	}
	int flag = 1;
	for (size_t i = 0; i <= length/2; i++)
	{
		if (DeQueue(Q) != PopStack(&S))
			flag = 0;
	}
	if (flag == 1) printf_s("YES");
	else printf_s("NO");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
