#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*ѡ������*/

void swap(int * a, int * b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void select_sort(int * arr, int sz)
{
	int j = 0;
	int i = 0;
	for(i = 0; i< sz - 1; i++)
	{
		int n = i;
		for( j = i+1; j< sz; j++)
		{
			if(arr[j] < arr[n])
			{
				n = j;
			}
		}
		if(arr[n] != arr[i]);
		{
			swap(&arr[n], &arr[i]);
		}
	}
}

int main()
{
	srand((int)time(0));
	int n = 0;
	int * arr = NULL;
	printf("�����������С��\n");
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	int i = 0;
	for( i = 0; i< n; i++)
	{
		arr[i] = rand()%100; 
	}
	printf("ԭ����˳��Ϊ��\n");
		for( i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	select_sort(arr, n);
	printf("ѡ�����������˳��Ϊ��\n");
	for( i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
