#include<stdio.h>
/*���������޷��ı�ʵ�ε�ֵ������ָ�룩*/
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
	
/*��ָ�뼴�ɸı�*/
	swap(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}
	
