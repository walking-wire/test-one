#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}node;

int main()
{
	node *head = NULL;
	int n = 0;
	scanf("%d",&n);
	int i = 0;
	for(i = 0; i<= n; i++)
	{
		node *p = (node*)malloc(sizeof(node));
		if(head == NULL)
		{
			head = p;
			head->data = i;
			head->next = NULL; 
		}
		else
		{
			node*last = head;
			while(last->next)
			{
				last = last->next;
			}
			p->data = i;
			p->next = NULL;
			last->next = p;
		}
	}
	node*ptr = head;
	for(ptr; ptr; ptr = ptr->next)
	{
		printf("%d ",ptr->data);
	}
	node*p1 = head;
	int k = 0;
	printf("\n");
	scanf("%d", &k);
	for(p1; p1; p1 = p1->next)
	{
		if(p1->data == k)
		{
			node*q = (node*)malloc(sizeof(node));
			q->data = 0;
			q->next = p1->next;//Á´±íÌí¼ÓÏî 
			p1->next = q;
			break;
		}
	}
	node*ptr1 = head;
	for(ptr1; ptr1; ptr1 = ptr1->next)
	{
		printf("%d ",ptr1->data);
	}
	return 0;
}
