#include<stdio.h>

union un
{
	unsigned int a;
	unsigned char n[4];
}UN = {22334455};//��aת��Ϊ16���ƣ�����ΪС�˴洢�����䷭ת��1���ֽ�1���ֽڵĶ�ȡ 

int main()
{
	printf("%d %d %d %d",UN.n[0],UN.n[1],UN.n[2],UN.n[3],UN.n[4]);
	return 0;
}
