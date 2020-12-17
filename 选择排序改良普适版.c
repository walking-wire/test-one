#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*选择排序改良版*/

int cmp(void*e1, void*e2)
{
	if((*(double*)e1) - (*(double*)e2) > 0)
	{
		return 1;
	}
	else if((*(double*)e1) - (*(double*)e2) == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void swap(char * a, char * b, int width)
{
	int i = 0;
	for( i = 0; i< width ; i++)
	{
		int tmp = 0;
		tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

void select_sort(void* arr, int sz, int width, int (*p)(void*e1, void*e2))
{
	int i = 0;
	int left = 0;
	int right = sz - 1;
	int min = 0;
	int max = 0;
	while(left<right)
	{
		max = left;
		min = left;
		for(i = left+1; i<= right; i++)
		{
			if(cmp(((char*)arr+min*width), ((char*)arr+i*width)) > 0)
			{
				min = i;
			}
			if(cmp(((char*)arr+max*width), ((char*)arr+i*width)) < 0)
			{
				max = i;
			}
		}
		if( min != left)
		{
			swap((char*)arr+min*width, (char*)arr+left*width, width);
		}
		if(max == left)
		{
			max = min;
		}
		if( max != right)
		{
			swap((char*)arr+max*width, (char*)arr+right*width, width);
		}
		left++;
		right--;
	}
}

int main()
{
	srand((int)(time(0)));
	int n = 0;
	printf("请输入数组大小：\n");
	scanf("%d",&n);
	double * arr;
	arr = (double*)malloc(sizeof(double)*n);
	int i = 0;
	printf("原数组顺序为：\n");
	for( i = 0; i< n; i++)
	{
		arr[i] = rand()%100*0.1/7;
		printf("%.2f ",arr[i]);
	}
	printf("\n");
	printf("排序后数组顺序为：\n");
	select_sort(arr, n, sizeof(arr[0]), cmp);
	for(i = 0; i< n; i++)
	{
		printf("%.2f ",arr[i]);
	}
	return 0;
}
