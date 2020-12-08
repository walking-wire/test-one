#include<stdio.h>
# define arr_SIZE 5
/*用指针将数字逆序排列*/
void swap(int* a , int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void reverse(int arr[arr_SIZE])
{
	int* pa = NULL;
	int i = 0,j = 0;
	for(i=1;i<arr_SIZE;i++)
	{
		pa = &arr[0];
		for(j=0;j<arr_SIZE-i;j++)
		{
			if(*(pa+1)!='\0')
			{
			swap(pa,pa+1);
			pa++;
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[arr_SIZE] = { 0 };
	for(i=0;i<arr_SIZE;i++)
	{
		scanf("%d",&arr[i]);
	}
	reverse(arr);
	for(i=0;i<+arr_SIZE;i++)
	{
		printf("%6d",arr[i]); 
	}
	return 0;
}
	
