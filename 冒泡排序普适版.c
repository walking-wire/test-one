#include<stdio.h>

void swap(char*a, char*b, int width)
{
	int i = 0;
	for(i = 0; i< width; i++)
	{
		int temp = 0;
		temp = *a;
		*a = *b;
		*b = temp;
		a++;
		b++;
	}
}

int cmp(const void*a,const void*b)
{
	return ((*(double*)(a)-*(double*)(b)));
}

void Bubble_sort(void* arr, int size,int width, int (*cmp)(const void*a,const void*b))
{
	int i = 0;
	for( i = 0; i< size-1; i++)
	{
		int j = 0;
		for(j = 0; j< size-i-1; j++)
		{
			if(cmp( (char*)arr+j*width, (char*)arr+width*(j+1) )>=0)
			{
				swap((char*)arr+j*width, (char*)arr+width*(j+1),width);
			}
		}
	}
}

int main()
{
	double arr[5] = { 1.2 , 1.3 , 2.3 , 0.2 , 0 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	Bubble_sort(arr,sz,sizeof(double),cmp);
	int i = 0;
	for(i = 0 ; i< 5; i++)
	{
		printf("%.2f\t",arr[i]);
	}
	return 0;
}
