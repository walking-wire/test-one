#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next; 
}NODE;

typedef struct list
{
	NODE *head;
	NODE *tail; 
}LIST;
int main()
{
	LIST List;
	List.head = (NODE*)malloc(sizeof(NODE));//head为头指针指向头结点，头结点中数据域为空，创建头结点为了方便删除第一个链表元素 
	List.head->next = NULL;
	List.tail = List.head;
	int n = 0;
	scanf("%d",&n);
	while(n != 0)
	{
		NODE *p = (NODE*)malloc(sizeof(NODE));
		p->data = n;
		p->next = NULL;
		List.tail->next = p;
		List.tail = p;
		n--;
	}
	NODE *ptr = List.head->next;
	for(ptr; ptr ; ptr = ptr->next)
	{
		printf("%d ",ptr->data);
	}
	return 0;
}
