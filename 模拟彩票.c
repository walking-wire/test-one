#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Arr_size 6

int main()
{
	int *arr;
	arr = (int*)malloc(sizeof(int)*Arr_size);
	srand((int)(time(0)));
	
	int i = 0;
	for(i = 0; i< Arr_size; i++)
	{
		arr[i] = rand();
	}
	
	int *TD;
	TD = (int*)malloc(sizeof(int)*Arr_size);
	printf("请依次输入6个数字：\n");
	for(i = 0; i< Arr_size; i++)
	{
		scanf("%d",&TD[i]);
	}
	
	int *p1 = &arr[0];
	int *p2 = &TD[0];
	int num = 0;
	for(i = 0; i < Arr_size; i++)
	{
		int j = 0;
		for(j = 0; j <Arr_size; j++)
		{
			if(*p2 == *p1)
			{
				num++;
			}
			p1++;
		}
		p2++;
	}
	printf("%d",num);
	return 0;
}
