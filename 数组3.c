#include<stdio.h>
/*求数组和与平均值*/
int main()
{
	int n = 0 , k = 0,q = 0,sum = 0 , arr[100];
	printf("请输入您想定义的数组大小");
	scanf("%d",&n);
	for(k;k<n;k++)
	{
		scanf("%d",&q);
		arr[k] = q;
		sum += q;
	}
	printf("该数组和为%d,平均值为%.2f",sum,(float)(sum/n));
	return 0;
}
