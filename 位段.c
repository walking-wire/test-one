#include<stdio.h>

/*位段*/
struct S
{
	int a : 2;
	int b : 10;
	int c : 21;
	int d : 31;//比特位 
};//最后一个位段不能大于32 

int main()
{
	struct S s ;
	printf("%d ",sizeof(s));//八个字节 
	return 0;
}
