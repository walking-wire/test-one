#include<stdio.h>
#include<stdlib.h>

typedef struct DLinkList
{
	int data;
	struct DLinkList *pior;
	struct DLinkList *next;
}DL;

bool inDL(DL* &head)
{
	head->next = NULL;
	head->pior = NULL;
	return true;
}

bool printDL(DL * head)
{
	head = head->next;
	while(head)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	return true;
}

bool DeleteDL(DL* ret)
{
	if(!ret)
	{
		return false;
	}
	DL * bef = ret->pior;
	bef->next = ret->next;
	ret->next = bef;
	free(ret);
	ret = NULL;
	return true;
}

int main()
{
	DL *head = (DL*)malloc(sizeof(DL));
	inDL(head);
	int sz = 5;
	for(sz; sz > 0; sz--)
	{
		DL* tmp = (DL*)malloc(sizeof(DL));
		tmp->pior = head;
		tmp->next = head->next;
		head->next = tmp;
		tmp->data = sz;
	}
	printDL(head);
	DeleteDL(head->next);
	printDL(head);
	return 0;
}
