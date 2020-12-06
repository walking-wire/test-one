#include<stdio.h>
void jzzz(int n,int num)
{
	int arr[10],i = 0;
	for(n;n!=0;)
	{
		arr[i] = n%num;
		i++;
		n /= num;
	}
	i -= 1;
	for(i;i>=0;i--)
	{
	printf("%d",arr[i]);
	}
}
int main()
{
	int n = 0,k = 0;
	printf("请输入您想处理的数:");
	scanf("%d",&n);
	printf("请输入您想转化的进制:");
	scanf("%d",&k);
	jzzz(n,k);
	return 0;
}
