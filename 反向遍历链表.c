#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node* createlinklist(int n)
{
	node *head = (node*)malloc(sizeof(node));
	head->next = NULL;
	head->data = n;
	return head;
}

void reverseprint(node*head)//递归反向遍历链表 
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		reverseprint(head->next);
		printf("%d ",head->data);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	node*HEAD = createlinklist(0);
	for(int i = 1; i< n; i++)
	{
		node*p = (node*)malloc(sizeof(node));
		p->data = i;
		p->next = NULL;
		node*q = HEAD;
		while(q->next)
		{
			q = q ->next;
		}
		q->next = p;
	}
	node*ptr = HEAD;
	for(ptr; ptr; ptr = ptr->next)
	{
		printf("%d ", ptr->data);
	}
	printf("\n");
	reverseprint(HEAD);
	return 0;
}
