#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode * next;
}ListN;

ListN* createList(int* nums, int size)//创建链表 
{
	ListN* head = (ListN*)malloc(sizeof(ListN));
	ListN* headcopy = head;
	for(int i = 0; i< size; i++)
	{
		ListN* p = (ListN*)malloc(sizeof(ListN));
		head->next = p;
		p->val = nums[i];
		p->next = NULL;
		head= head->next;
	}
	head->next = NULL;
	return headcopy->next;
}

ListN* Combine(ListN* l1, ListN* l2)//合并两个链表 
{
	ListN* head = (ListN*)malloc(sizeof(ListN));
	ListN* headcopy = head;
	while(l1 && l2)
	{
		if(l1->val > l2->val)
		{
			head->next = l2;
			l2 = l2->next;
		}
		else
		{
			head->next = l1;
			l1 = l1->next;
		}
		head = head->next;
	}
	if(l1)
	{
		head->next = l1;
	}
	if(l2)
	{
		head->next = l2; 
	}
	return headcopy->next;
}

void Print(ListN* head)//输出链表 
{
	while(head)
	{
		printf("%d ",head->val);
		head = head->next;
	}
}

int main()
{
	int size1 = 0;
	int size2 = 0;
	printf("请输入第一个链表的长度：\n");
	scanf("%d",&size1);
	printf("请输入第二个链表的长度：\n");
	scanf("%d",&size2);
	int* nums1 = (int*)malloc(sizeof(int) * size1);
	int* nums2 = (int*)malloc(sizeof(int) * size2);
	printf("请输入第一个链表的每一个元素：\n");
	for(int i = 0; i< size1; i++)
	{
		scanf("%d",&nums1[i]);
	}
	printf("请输入第二个链表的每一个元素：\n");
	for(int i = 0; i< size2; i++)
	{
		scanf("%d",&nums2[i]);
	}
	ListN* l1 = createList(nums1,size1);
	ListN* l2 = createList(nums2,size2);
	ListN* head = Combine(l1, l2);
	printf("合并后结果为：\n"); 
	Print(head);
	return 0;
}
