#include<stdio.h>
/*副函数中无法改变实参的值（不用指针）*/
void swap(int a, int b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
void swap(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a = 10,b = 20;
	swap(a,b);
	printf("%d %d\n",a,b);
	
/*用指针即可改变*/
	swap(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}
	
