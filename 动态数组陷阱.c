#include<stdio.h>
#include<stdlib.h>
/*sizeof�޷�ȡ�ö�̬����Ĵ�С*/
int main()
{
	int n = 0;
	printf("�����������С��");
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(4*n);
	printf("%d",sizeof(arr));
	return 0;
}
