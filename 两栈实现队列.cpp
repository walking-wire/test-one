#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
//双栈实现队列 
typedef struct NewQueue//双栈化队列 
{
	int *Stack1;
	int *Stack2;
	int top1;
	int top2;
}NQ;

NQ* NEWQueueInitial()//队列初始化 
{
	NQ* NQueue = (NQ*)malloc(sizeof(NQ));
	NQueue->Stack1 = (int*)malloc(sizeof(int) * SIZE);
	NQueue->Stack2 = (int*)malloc(sizeof(int) * SIZE);
	NQueue->top1 = 0;
	NQueue->top2 = 0;
	return NQueue;
}

void InQueue(NQ *NQueue, int number)//入列 
{
	NQueue->Stack1[NQueue->top1] = number;
	NQueue->top1++; 
}

int OutQueue(NQ *NQueue)//出列 
{
	if(NQueue->top2==0)//当第二个栈为空，说明new队列中无元素 
	{
        if(NQueue->top1 == 0)//如果第一个栈为空，说明未读取数据，返回-1表示运行错误 
        {
        	return -1;
		}
		while(NQueue->top1 != 0)
		{
			NQueue->Stack2[NQueue->top2] = NQueue->Stack1[NQueue->top1];//将栈1元素逆向放入栈2，从而实现队列 
			NQueue->top2++;
			NQueue->top1--; 
		}
    }
    NQueue->top2--;
    return NQueue->Stack2[NQueue->top2];//返回出列元素 

}

int GetFirst(NQ *NQueue)//获取队首元素 
{
	return NQueue->Stack2[NQueue->top2];
}

void CancelQueue(NQ *NQueue)//销毁队列
{
	free(NQueue->Stack1);
	free(NQueue->Stack2);
	free(NQueue);
}

int main()
{
	NQ *newqueue = NEWQueueInitial();//创建new队列 
	printf("请输入入队列元素个数：\n");
	int sz = 0;
	scanf("%d",&sz);
	printf("请输入一系列入队列元素：\n");
	int n1 = 0;
	for(sz; sz> 0; sz--)
	{
		scanf("%d",&n1);
		InQueue(newqueue,n1);
	}
	printf("第一次出队列元素后,队首元素为");
	OutQueue(newqueue);
	printf("%d\n",GetFirst(newqueue));
	printf("第二次出队列元素后,队首元素为");
	OutQueue(newqueue);
	printf("%d",GetFirst(newqueue));
	CancelQueue(newqueue);//销毁队列 
	return 0;
}
