#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
//˫ջʵ�ֶ��� 
typedef struct NewQueue//˫ջ������ 
{
	int *Stack1;
	int *Stack2;
	int top1;
	int top2;
}NQ;

NQ* NEWQueueInitial()//���г�ʼ�� 
{
	NQ* NQueue = (NQ*)malloc(sizeof(NQ));
	NQueue->Stack1 = (int*)malloc(sizeof(int) * SIZE);
	NQueue->Stack2 = (int*)malloc(sizeof(int) * SIZE);
	NQueue->top1 = 0;
	NQueue->top2 = 0;
	return NQueue;
}

void InQueue(NQ *NQueue, int number)//���� 
{
	NQueue->Stack1[NQueue->top1] = number;
	NQueue->top1++; 
}

int OutQueue(NQ *NQueue)//���� 
{
	if(NQueue->top2==0)//���ڶ���ջΪ�գ�˵��new��������Ԫ�� 
	{
        if(NQueue->top1 == 0)//�����һ��ջΪ�գ�˵��δ��ȡ���ݣ�����-1��ʾ���д��� 
        {
        	return -1;
		}
		while(NQueue->top1 != 0)
		{
			NQueue->Stack2[NQueue->top2] = NQueue->Stack1[NQueue->top1];//��ջ1Ԫ���������ջ2���Ӷ�ʵ�ֶ��� 
			NQueue->top2++;
			NQueue->top1--; 
		}
    }
    NQueue->top2--;
    return NQueue->Stack2[NQueue->top2];//���س���Ԫ�� 

}

int GetFirst(NQ *NQueue)//��ȡ����Ԫ�� 
{
	return NQueue->Stack2[NQueue->top2];
}

void CancelQueue(NQ *NQueue)//���ٶ���
{
	free(NQueue->Stack1);
	free(NQueue->Stack2);
	free(NQueue);
}

int main()
{
	NQ *newqueue = NEWQueueInitial();//����new���� 
	printf("�����������Ԫ�ظ�����\n");
	int sz = 0;
	scanf("%d",&sz);
	printf("������һϵ�������Ԫ�أ�\n");
	int n1 = 0;
	for(sz; sz> 0; sz--)
	{
		scanf("%d",&n1);
		InQueue(newqueue,n1);
	}
	printf("��һ�γ�����Ԫ�غ�,����Ԫ��Ϊ");
	OutQueue(newqueue);
	printf("%d\n",GetFirst(newqueue));
	printf("�ڶ��γ�����Ԫ�غ�,����Ԫ��Ϊ");
	OutQueue(newqueue);
	printf("%d",GetFirst(newqueue));
	CancelQueue(newqueue);//���ٶ��� 
	return 0;
}
