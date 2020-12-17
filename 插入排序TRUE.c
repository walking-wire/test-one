#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*插入排序*/

void insert_sort(int *arr, int sz)
{
	int i = 0;
	int j = 0;
	for( i = 1; i< sz; i++)
	{
		if(arr[i]<arr[i-1])
		{
			int tmp = arr[i];
			arr[i] = arr[i-1];
			int j = 0;
			for(j = i - 2 ; j>=0 && tmp< arr[j]; j--)
			{
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main()
{
	srand((int)time(0));
	printf("请输入数组大小：\n");
	int n = 0;
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);
	int i = 0;
	printf("未插入排序前的数组顺序：\n");
	for( i = 0; i< n; i++)
	{
		arr[i] = rand()%100;
		printf("%d ",arr[i]);
	}
	printf("插入排序后的数组顺序：\n");
	insert_sort(arr, n);
	for(i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
