#include<stdio.h>
/*求n以内的勾股数*/
int Gou(int n)
{
	int a= 1, b = 1, c = 1;
	for(a = 1;a<=n;a++)
	{
		for(b = a;b<=n; b++)
		{
			for(c = a;c<=n;c++)
			{
				if(a*a+b*b==c*c)
				{
					printf("%6d %6d %6d\n",a,b,c);
				}
			}
		}
	}
}
int main()
{
	int n = 0;
	printf("请输入一个数：");
	scanf("%d",&n);
	Gou(n);
	return 0;
}
