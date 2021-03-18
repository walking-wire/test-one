#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode * next;
}ListN;

ListN* createList(int size)//����ѭ������ 
{
	ListN* head = (ListN*)malloc(sizeof(ListN));
	ListN* headcopy = head;
	head->val = 1;
	for(int i = 2; i< size+1; i++)
	{
		ListN* p = (ListN*)malloc(sizeof(ListN));
		head->next = p;
		p->val = i;
		head = p;
	}
	head->next = headcopy;
	return headcopy;
}

void GameBegin(int outnum, ListN*head)//��ʼ���ж��� 
{
	ListN* newhead = (ListN*)malloc(sizeof(ListN));
	ListN* newheadcopy = newhead;
	ListN* front = head->next;
	while(front->next != front)
	{
		int j = 1;
		while(j != outnum - 1)
		{
			head = front;
			front = front->next;
			j++;
		}
		printf("%d->",front->val);
		newhead->next = front;
		newhead = newhead->next;
		head->next = front->next;
		head = front->next;
		front = head->next;
	}
	printf("%d",front->val);
}

int main()
{
	int size = 0;
	printf("�������ж��ٸ���Χ��һ������\n");
	scanf("%d",&size);
	int outnum = 0;
	printf("�����뱨���ڼ�����ʱ�뿪��\n");
	scanf("%d",&outnum);
	ListN* head = createList(size);
	printf("�������Ϊ��\n");
	GameBegin(outnum, head);
	return 0;
}
