#include<stdio.h>
#include<stdlib.h>
/*sizeof无法取得动态数组的大小*/
int main()
{
	int n = 0;
	printf("请输入数组大小：");
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(4*n);
	printf("%d",sizeof(arr));
	return 0;
}
