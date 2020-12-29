#include<stdio.h>

union un
{
	unsigned int a;
	unsigned char n[4];
}UN = {22334455};//将a转化为16进制，又因为小端存储，将其翻转后1个字节1个字节的读取 

int main()
{
	printf("%d %d %d %d",UN.n[0],UN.n[1],UN.n[2],UN.n[3],UN.n[4]);
	return 0;
}
