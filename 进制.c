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
	printf("���������봦�����:");
	scanf("%d",&n);
	printf("����������ת���Ľ���:");
	scanf("%d",&k);
	jzzz(n,k);
	return 0;
}
