#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*冒泡排序改良版*/

void swap(char * a , char * b, int width)
{
	int i = 0;
	for(i = 0; i< width; i++)
	{
		int tmp = 0;
		tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

int cmp(const void* e1, const void* e2)
{
	if(*(int*)(e1) - (*(int*)(e2)) > 0)
	{
		return 1;
	}
	else if (*(int*)(e1) - (*(int*)(e2)) == 0)//对于int类型排序 可以将左边的if三段改为return (int)(*(int)e1 - *(int)e2) 
	{
		return 0;
	}
	else if (*(int*)(e1) - (*(int*)(e2)) < 0)
	{
		return -1;
	}
}

void Bubble_sort(void * arr, int sz,int width, int (*p)(const void* e1, const void* e2))
{
	int i = 0;
	for(i = 0; i< sz-1; i++)
	{
		int j = 0;
		int flag = 1;
		for(j = 0; j< sz-i-1; j++)
		{
			if(cmp((char*)arr+j*width, (char*)arr+(j+1)*width) > 0)
			{
				swap((char*)arr+j*width, (char*)arr+(j+1)*width, width);
				flag = 0;
			}
		}
		if(flag == 1)//如果该趟判断结束后未进行元素交换则说明该数组已排好序，无需再进行下一趟的冒泡排序 
		{
			return;
		}
	}
}

int main()
{
	srand((int)time(0));
	int sz = 0;
	printf("请输入数组大小：\n");
	scanf("%d",&sz);
	int * arr = NULL;
	arr =(int*)malloc(sizeof(int)*sz);
	int i = 0;
	printf("原数组顺序为：\n");
	for( i = 0; i< sz; i++)
	{
		arr[i] = rand()%100;
		printf("%d ",arr[i]);
	}
	printf("\n");
	Bubble_sort(arr, sz, sizeof(arr[0]), cmp);
	printf("排序后数组顺序为：\n");
	for(i = 0; i< sz; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
