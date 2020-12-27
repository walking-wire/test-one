#include<stdio.h>

//喝汽水，一瓶一元，2个空瓶可以换一瓶，问，有N元能喝多少瓶？ 

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
