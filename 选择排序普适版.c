#include<stdio.h>

/*—°‘Ò≈≈–Ú∆’  ∞Ê*/

struct STU
{
	float c1;
	char c2;
};

void swap(char*a, char*b, int width)
{
	int i = 0;
	for(i = 0; i< width; i++)
	{
		char tmp = 0;
		tmp = *a;
		*a = *b;
		*b= tmp;
		a++;
		b++;
	}
}

double cmp(void*e1, void*e2)
{
	return (double)((((struct STU*)(e1))->c1)-(((struct STU*)(e2))->c1));
}

void select_sort(void* arr, int sz, int width, double (*p)(void*e1, void*e2))
{
	int i = 0;
	for( i = 0; i< sz-1; i++)
	{
		int m = i;
		int j = 0;
		for(j = i+1; j< sz; j++)
		{
			if(cmp((char*)arr+m*width, (char*)arr+j*width)> 0)
			{
				m = j;
			}
			swap((char*)arr+m*width, (char*)arr+i*width, width);
		}
	}
}

int main()
{
	struct STU arr[5];
	arr[0].c1 = 1.2;
	arr[1].c1 = 2.3;
	arr[2].c1 = 0.0;
	arr[3].c1 = 10.2;
	arr[4].c1 = 5.3;
	int sz = sizeof(arr)/sizeof(arr[0]);
	select_sort(arr, sz, sizeof(arr[0]), cmp);
	int i = 0;
	for(i = 0; i< sz; i++)
	{
		printf("%f ",arr[i].c1);
	}
	return 0;
}
