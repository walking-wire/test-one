#include<stdio.h>
int Add(int a, int b)
{
	return a+b;
}
int Sub(int a, int b)
{
	return a-b;
}
int main()
{
	int (*p[2])(int,int) = {Add,Sub};//����ָ������ 
	printf("%d",(*p[0])(10,10));
	return 0;
}
