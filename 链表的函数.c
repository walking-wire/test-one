#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next; 
}node;

typedef struct _list
{
	node *head;
}list;

void Add(list *plist, int n)
{
	node*p = (node*)malloc(sizeof(node));
	p->data = n;
	p->next = NULL;
	node*last = plist->head;
	if(last != NULL)
	{
		while(last->next)
		{
			last = last->next;
		}
		last->next = p; 
	}
	else
	{
		plist->head = p;
	}
}

bool Search(list *plist, int num)
{
	node*p = plist->head;
	for(p;p;p = p->next)
	{
		if(p->data == num)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int n = 0;
	list list0;
	list0.head = NULL;
	while(n != -1)
	{
		scanf("%d", &n);
		if(n!= -1)
		{
			Add(&list0,n);
		}
	}
	printf("\n");
	int num = 0;
	scanf("%d",&num);
	printf("%d",Search(&list0, num));
	return 0;
}
