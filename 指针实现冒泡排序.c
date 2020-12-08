#include<stdio.h>
# define arr_Size 5
/*÷∏’Î µœ÷√∞≈›≈≈–Ú*/
void swap(int* pa, int* pb)
{
	int temp = 0;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main()
{
	int i = 0, j = 0;
	int arr[arr_Size] = { 0 };
	for(i=0;i<arr_Size;i++)
	{
		scanf("%d",&arr[i]);
	}
	i = 0;
	for(i=1;i<arr_Size;i++)
	{
		for(j=0;j<arr_Size-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
	for(i=0;i<arr_Size;i++)
	{
		printf("%6d",arr[i]);
	}
	return 0;
}
