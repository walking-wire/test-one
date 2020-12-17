#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/*插入值后重新排序*/

int cmp(const void*e1 , const void*e2)
{
	return *(int*)(e1) - *(int*)e2;
}

int insert_sort(int *arr, int sz, int num)
{
	int i = 0;
	int k = 0;
	for( i = 0; i< sz; i++)
	{
		if(num<arr[i])
		{
			k = i;
			break;
		}
		if(num< arr[0])
		{
			k = i = 0;
			break;
		}
	}
	int tmp = arr[k];
	for(k; k< sz;k++)
	{
		int current = tmp;
		tmp = arr[k+1];
		arr[k+1] = current;
	}
	arr[i] = num;
}

int main()
{
	int *arr = NULL;
	int n = 0;
	printf("请输入数组大小：\n");
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	int i = 0;
	srand((int)time(0));
	printf("排序前数组顺序为：\n");
	for( i = 0; i< n; i++)
	{
		arr[i] = rand()%100;
		printf("%d ",arr[i]);
	}
	printf("\n");
	qsort(arr , n , sizeof(arr[0]),cmp);
	printf("插入前排序后的数组顺序为：\n");
	for(i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("请输入需要插入的值：\n");
	int num = 0;
	scanf("%d",&num);
	insert_sort(arr, n, num);
	printf("插入并排序后的数组顺序为：\n");
	for( i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0; 
}
