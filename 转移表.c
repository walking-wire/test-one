#include<stdio.h>
/*ת�Ʊ�*/
/*ʵ�ּ��׼�����*/
int Add(int x , int y)
{
	return (x+y);
}
int Sub(int x , int y)
{
	return (x-y);
}
int Mul(int x , int y)
{
	return (x*y);
}
int Div(int x , int y)
{
	return (x/y);
}
int main()
{
	int input = 1;
	while(input)
	{
		printf("*******************\n");
		printf("**1. add   2. sub**\n");
		printf("**3. mul   4. div**\n");
		printf("******0. exit******\n");
		int(*p[5])(int , int) = {0 , Add , Sub , Mul , Div};
		printf("��������Ҫ���еĲ�����ţ�\n");
		scanf("%d",&input);
		if(input>=1&&input<=4)
		{
			int a = 0 , b = 0;
			printf("��������Ҫ��������������\n");
			scanf("%d %d",&a,&b);
			int result = (*p[input])(a , b);
			printf("%d\n",result);
		}
		else
		{
			break;
		}
	}
	return 0;
}
