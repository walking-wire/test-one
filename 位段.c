#include<stdio.h>

/*λ��*/
struct S
{
	int a : 2;
	int b : 10;
	int c : 21;
	int d : 31;//����λ 
};//���һ��λ�β��ܴ���32 

int main()
{
	struct S s ;
	printf("%d ",sizeof(s));//�˸��ֽ� 
	return 0;
}
