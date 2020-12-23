#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
}Node;

typedef struct List
{
	Node *head;
}List;

int main()
{
	List list;
	list.head = NULL;
	int n = 0;
	while(n != -1)
	{
		scanf("%d",&n);
		if(n != -1)
		{
			Node *ptr = (Node*)malloc(sizeof(Node));
			ptr->num = n;
			ptr->next = NULL;
			Node *last = list.head;
			if(last != NULL)
			{
				while(last)
				{
					last = last->next;
				}
				last = ptr;
			}
			else
			{
				list.head = ptr;
			}
		}
	}
	Node *pointer = list.head;
	while(pointer!=NULL)
	{
		printf("%d ",pointer->num);
		pointer = pointer->next;
	}
	return 0;
}
