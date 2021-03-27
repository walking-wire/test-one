#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

//Õ»Ïà¹Ø²Ù×÷ 
typedef struct 
{
	int arr[MAXSIZE];
	int top;
	int bottom;
}Stack;

void InitStack(Stack * &q)
{
	q = (Stack*)malloc(sizeof(Stack));
	q->top = q->bottom = -1; 
}

bool StackEmpty(Stack * q)
{
	if(q->top == q->bottom)
	{
		return true;
	}
	return false;
}

void DestroyStack(Stack * &q)
{
	free(q);
}

bool Pop(Stack * &q, int &number)
{
	if(q->top == q->bottom)
	{
		return false;
	}
	number = q->arr[q->top];
	q->top--;
	return true;
}

bool Push(Stack * q, int number) 
{
	if(q->top == MAXSIZE - 1)
	{
		return false;
	}
	q->top++;
	q->arr[q->top] = number;
	return true;
}

int main()
{
	Stack * mark = NULL;
	InitStack(mark);
	printf("%d..\n", StackEmpty(mark));
	Push(mark,1);
	Push(mark,2);
	int num = 0;
	Pop(mark, num);
	printf("%d\n", num);
	printf("%d..\n", StackEmpty(mark));
	DestroyStack(mark);
	return 0;
}
