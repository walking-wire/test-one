#include<stdio.h>
#define arr_size 10
/*n（n<=500）以内的10个最大素数及其和*/
int search(int num)
{
	int i = 0;
	for(i=2;i<=num-1;i++)
	{
		if(num%i==0)
		{
			return 0;
		}
	}
	return num;
}
int main()
{
	int n = 0,k = 2,i = 0;
	int arr[arr_size] = {0};
	printf("请输入需要查找的范围最大值(不超过500):");
	scanf("%d",&n);
	for(k=n;k>=2;k--)
	{
		if(search(k)!=0)
		{
			arr[i] = k;
			i++;
		}
	}
	i = 0;
	int sum = 0;
	for(i=0;i<arr_size;i++)
	{
		if(arr[i]!=0)
		{
		printf("%6d",arr[i]);
		sum += arr[i];
		}
	}
	printf("\n");
	printf("sum=%d\n",sum);
/*二分查找*/
	printf("请输入您需要查找的数：");
	scanf("%d",&n);
	i = (int)(arr_size/2);
	for(int j = 0;j<4;j++)
	{
		if(n<arr[i])
		{
			i = (int)((i+arr_size)/2);
		}
		else if(n>arr[i])
		{
			i = (int)((0+i)/2);
		}
		else
		{
			printf("该数字为本数组的第%d个",i+1);
			return 0;
		}
	}
	printf("该数不存在与本数组中");
	return 0;
}
