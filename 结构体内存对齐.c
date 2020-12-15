#include<stdio.h>

//结构体内存对齐 
struct S1
{
	char c1;
	char c2; 
	double x1;
};

struct S2 
{
	char c1;
	double x1;
	char c2;
};
int main()
{
	struct S1 s1 = { 0 };
	struct S2 s2 = { 0 };
	printf("%d ",sizeof(s1));//(2+6)+8 
	printf("%d ",sizeof(s2));//(1+7)+8+1+7
	return 0;
}
