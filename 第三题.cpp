#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode
{
	char letter;
	struct ListNode *pre;
	struct ListNode *next;
}ListN;

ListN* createList(char* word)//����˫���� 
{
	ListN* head = (ListN*)malloc(sizeof(ListN));
	ListN* headcopy = head;
	head->pre = NULL; 
	for(int i = 0; i< strlen(word); i++)
	{
		ListN* p = (ListN*)malloc(sizeof(ListN));
		head->next = p;
		p->pre = head;
		p->letter = word[i];
		head = p;
	}
	head->next = NULL;
	return headcopy;
}

void Insertletter(ListN* head,int position, char key)//����Ԫ�� 
{
	for(int i = 0; i< position; i++)
	{
		head = head->next;
	}
	ListN* before = head->pre;
	ListN* q = (ListN*)malloc(sizeof(ListN));
	q->letter = key;
	q->pre = before;
	q->next = head;
	before->next = q;
	head->pre = q;
}

void Delete(ListN* head ,int position)//ɾ��Ԫ�� 
{
	for(int i = 0; i< position; i++)
	{
		head = head->next;
	}
	ListN* tmp1 = head->pre;
	ListN* tmp2 = head->next;
	tmp1->next = tmp2;
	tmp2->pre = tmp1;
}

void Print(ListN* head)//������� 
{
	head = head->next;
	while(head)
	{
		printf("%c",head->letter);
		head = head->next;
	}
}

void Free(ListN* head)//�ͷ�����
{
	ListN* headforward = head->next;
	while(headforward)
	{
		free(head); 
		head = headforward;
		headforward = headforward->next;
	}
}

int main()
{
	int size = 0;
	printf("�������ַ�����С��\n");
	scanf("%d",&size);
	char* word = (char*)malloc(size);
	printf("�������ַ�����\n");
	scanf("%s",word);
	ListN* head = createList(word);
	Insertletter(head,4,'f');//��Ŀ(1)
	Delete(head,5);//��Ŀ(2) 
	Print(head);//��Ŀ(3) 
	Free(head);//��Ŀ(4)
	return 0;
}
