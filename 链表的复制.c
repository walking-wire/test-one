#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}NODE;

int main()
{
	NODE *head1 = (NODE*)malloc(sizeof(NODE));
	head1->next = NULL;
	NODE *tail1 = head1;
	int n = 0;
	scanf("%d",&n);
	for(n;n;n--)
	{
		NODE *p = (NODE*)malloc(sizeof(NODE));
		p->data = n;
		p->next = NULL;
		tail1->next = p;
		tail1 = p;
	}
	NODE *tmp = head1->next;
	NODE *head2 = (NODE*)malloc(sizeof(NODE));
	head2->next = NULL;
	NODE *tail2 = head2;
	while(tmp->next)
	{
		NODE *pk = (NODE*)malloc(sizeof(NODE));
		pk->next = tmp->next;
		pk->data = tmp->data;
		tail2->next = pk;
		tail2 = pk;
		tmp = tmp->next;
	}
	NODE *ptr = head2->next;
	for(ptr;ptr;ptr = ptr->next)
	{
		printf("%2d ",ptr->data);
	}
	return 0;
}
