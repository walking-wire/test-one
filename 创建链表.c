#include<stdio.h>
#include<stdlib.h>

/*创建链表*/

typedef struct node 
{
	int number;
	struct node *next;//创建一个包含数据与指向本类型的指针的结构体 
}node;

int main()
{
	node *head = NULL;//创建头指针 
	int n = 0;
	while(n != -1)
	{
		scanf("%d",&n);
		if(n!= -1)
		{ 
			node *p = (node*)malloc(sizeof(node));//创建末尾添加的指针p，其指向一块node类型的结构体 
			p->number = n;//将p指向node类型的结构体中的数据赋值为n 
			p->next = NULL;//让p指向node类型的结构体中的指针赋为NULL 
			node * last = head;//创建last-node类型的结构体的指针 
			if(last != NULL)//空指针不能用->符号访问 
			{
				while(last->next != NULL)//相当于遍历 
				{
					last = last->next;
				}
				last = p;
			}
			else
			{
				head = p;
			}
		}
	}
	return 0;
}
