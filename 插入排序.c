#include<stdio.h>
#include<stdlib.h>
/*��������*/
int swap(int *a , int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
int Bubblesort(int arr[],int n)
{
	int i = 0;
	int j = 0;
	for(i = 0; i< n - 1; i++)
	{
		for(j = 0; j< n - i - 1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}
int Insert(int arr[], int n)
{
	int i = 0;
	int *p = &n;
	for(i = 0; i<sizeof(arr); i++)
	{
		if(n<=arr[i])
		{
			swap(p,&arr[i]);
		}
	}
	i++;
	for(i; i<sizeof(arr); i++)
	{
		swap(p,&arr[i]);
	}
}		
int main()
{
	int n = 0;
	printf("��������Ҫ����������С��");
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(4*n);
	int i = 0;
	printf("������������Ҫ������������ĸ������֣�");
	for(i = 0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	Bubblesort(arr,n);
	int b = 0;
	printf("����������Ҫ��������֣�");
	scanf("%d",&b);
	Insert(arr,b);
	for(i = 0; i<n; i++)
	{
		printf("%5d",arr[i]);
	}
	return 0;
}
