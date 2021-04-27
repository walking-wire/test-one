// SeqList.h

#pragma once

#include <stdio.h>

#include <assert.h>

#include <stdlib.h>

 

typedef int SLDateType;

typedef struct SeqList

{

	SLDateType* a;

	size_t size;

	size_t capacity; // unsigned int

}SeqList;

 

// 对数据的管理:增删查改 

void SeqListInit(SeqList* ps);
{
	for(int i = 0; i< ps->size; i++)
	{
		ps->a[i] = 0;
	}
}

void SeqListDestory(SeqList* ps);
{
	free(ps);
}
 

void SeqListPrint(SeqList* ps);
{
	for(int i = 0; i< ps->capacity; i++)
	{
		printf("%d-", ps->a[i]);
	}
}

void SeqListPushBack(SeqList* ps, SLDateType x);
{
	if(ps->capacity == ps->size)	return;
	ps->a[ps->capacity++] = x;
}

void SeqListPushFront(SeqList* ps, SLDateType x);
{
	if(ps->capacity == ps->size)	return;
	for(int i = ps->capacity - 1; i>0; i--)
	{
		ps->a[i] = ps->a[i-1];
	}
	ps->a[0] = x;
	ps->capacity++;
}

void SeqListPopFront(SeqList* ps);
{
	if(!ps->capacity)	return;
	printf("%d\n",ps->a[0]);
	for(int i = 0; i< ps->capacity -1; i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	ps->capacity--;
}

void SeqListPopBack(SeqList* ps);
{
	if(!ps->capacity)	return;
	printf("%d\n",ps->a[capacity -1]);
	for(int i = ps->capacity -1; i>0 ; i++)
	{
		ps->a[i-1] = ps->a[i];
	}
	ps->capacity--;
}
 

// 顺序表查找

int SeqListFind(SeqList* ps, SLDateType x);
{
	for(int i = 0; i< ps->capacity; i++)
	{
		if(ps->a[i] == x)	return x;
	}
	return -1;
}

// 顺序表在pos位置插入x

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
{
	if(ps->capacity == ps->size)	return;
	for(int i = ps->capacity - 1; i> ps->pos; i--)
	{
		ps->a[i] = ps->a[i-1];
	}
	ps->a[pos] = x;
	ps->capacity++;
}

// 顺序表删除pos位置的值

void SeqListErase(SeqList* ps, size_t pos);
{
	if(!ps->capacity)	return;
	for(int i = ps->pos; i< ps->capacity - 1; i++)
	{
		ps->a[i+1] = ps->a[i];
	}
	ps->capacity--;
}
