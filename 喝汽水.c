#include<stdio.h>

//����ˮ��һƿһԪ��2����ƿ���Ի�һƿ���ʣ���NԪ�ܺȶ���ƿ�� 

void calculate(int money)
{
	int total = 0;
	int empty = 0;
	total = empty = money;
	while(empty>=2)
	{
		total += empty/2;
		empty = empty/2 + empty%2;
	}
	printf("%d\n",total);
}
int main()
{
	int money = 0;
	scanf("%d",&money);
	calculate(money);
	return 0;
}
