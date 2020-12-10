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
	int (*p[2])(int,int) = {Add,Sub};//函数指针数组 
	printf("%d",(*p[0])(10,10));
	return 0;
}
