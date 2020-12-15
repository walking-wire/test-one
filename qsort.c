#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	return *(double*)(a)-*(double*)(b);
}
int main()
{
	double arr[] = { 1.2, 0.2, 0.3, 4.0, 5};
	qsort(arr,5,sizeof(double),cmp);
	int i = 0; 
	for(i = 0; i< 5; i++)
	{
		printf("%.2f ",arr[i]);
	}
	return 0;
}
