#include<stdio.h>
/*���������ƽ��ֵ*/
int main()
{
	int n = 0 , k = 0,q = 0,sum = 0 , arr[100];
	printf("���������붨��������С");
	scanf("%d",&n);
	for(k;k<n;k++)
	{
		scanf("%d",&q);
		arr[k] = q;
		sum += q;
	}
	printf("�������Ϊ%d,ƽ��ֵΪ%.2f",sum,(float)(sum/n));
	return 0;
}
