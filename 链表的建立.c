#include<stdio.h>
#include<stdlib.h>
 
typedef struct _node
{
	int data;
	struct _node *next;
}NODE;

//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	NODE*head = (NODE*)malloc(sizeof(NODE));
//	head->next = NULL;
//	NODE*tail = head;
//	for(int i = 0; i< n; i++)
//	{
//		NODE*p = (NODE*)malloc(sizeof(NODE));
//		tail->next = p;
//		p->data = i;
//		p->next = NULL;
//		tail = p; 
//	}
//	NODE *ptr = head->next;
//	for(ptr; ptr; ptr = ptr->next)
//	{
//		printf("%d ",ptr->data);
//	}
//	return 0;
//}

int main()
{
	int n = 0;
	scanf("%d",&n);
	NODE*head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	NODE*tail = head;
	for(int i = 0; i< n; i++)
	{
		NODE*p = (NODE*)malloc(sizeof(NODE));
		p->next = tail->next;
		p->data = i;
		tail->next = p;
	}
	NODE* ptr = head->next;
	for(ptr; ptr; ptr = ptr->next)
	{
		printf("%d ",ptr->data);
	}
	return 0;
}
