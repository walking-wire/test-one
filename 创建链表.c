#include<stdio.h>
#include<stdlib.h>

/*��������*/

typedef struct node 
{
	int number;
	struct node *next;//����һ������������ָ�����͵�ָ��Ľṹ�� 
}node;

int main()
{
	node *head = NULL;//����ͷָ�� 
	int n = 0;
	while(n != -1)
	{
		scanf("%d",&n);
		if(n!= -1)
		{ 
			node *p = (node*)malloc(sizeof(node));//����ĩβ��ӵ�ָ��p����ָ��һ��node���͵Ľṹ�� 
			p->number = n;//��pָ��node���͵Ľṹ���е����ݸ�ֵΪn 
			p->next = NULL;//��pָ��node���͵Ľṹ���е�ָ�븳ΪNULL 
			node * last = head;//����last-node���͵Ľṹ���ָ�� 
			if(last != NULL)//��ָ�벻����->���ŷ��� 
			{
				while(last->next != NULL)//�൱�ڱ��� 
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
