#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}NODE;

int main()
{
	NODE*head = NULL;
	NODE*tail = NULL;
	int n = 0;
	scanf("%d",&n);
	for(n;n;n--)
	{
		NODE*p = (NODE*)malloc(sizeof(NODE));
		p->next = NULL;
		p->data = n;
		if(head == NULL)
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	NODE*ptr = head;
	for(ptr;ptr;ptr = ptr->next)
	{
		printf("%d ",ptr->data);
	}
	printf("Á´±íÏú»Ù");
	while(head->next != NULL)
	{
		NODE *pk = head->next;
		head->next = pk->next;
		free(pk);
	}
	return 0;
}
