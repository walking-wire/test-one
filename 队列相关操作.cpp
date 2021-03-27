#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20 
//队列的相关操作 

typedef struct sqQueue
{
	int arr[MAXSIZE];
	int front;
	int rear;
}Queue;

void InitQueue(Queue * &p)
{
	p = (Queue*)malloc(sizeof(Queue));
	p->front = p->rear = -1;
}

void DestroyQueue(Queue * &p)
{
	free(p);
}

bool QueueEmpty(Queue *p)
{
	if(p->front == p->rear) return true;
	return false;
}

bool enQueue(Queue * &p, int number)
{
	if(p->rear == MAXSIZE - 1)
	return false;
	p->rear++; 
	p->arr[p->rear] = number;
	return true;
}

bool deQueue(Queue * &p, int & returnnumber)
{
	if(p->front == p->rear) return false;
	p->front++;
	returnnumber = p->arr[p->front];
	return true;
}

int main()
{
	Queue * mark = NULL;
	InitQueue(mark);
	printf("%d..\n", QueueEmpty(mark));
	enQueue(mark, 1);
	enQueue(mark, 2);
	int num;
	deQueue(mark, num);
	printf("%d\n", num);
	printf("%d..", QueueEmpty(mark));
	DestroyQueue(mark);
	return 0;
}
