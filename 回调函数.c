#include<stdio.h>
/*���׼�����*/
void menu()
{
	printf("********************\n");
	printf("**1. Add    2. Sub**\n");
	printf("**3. Mul    4. Div**\n");
	printf("*******0. exit******\n");
}
int Add(int a, int b)
{
	return a+b;
}
int Sub(int a,int b)
{
	return a-b;
}
int Mul(int a,int b)
{
	return a*b;
}
int Div(int a, int b)
{
	return a/b;
}
void Cac(int (*p)(int,int))
{
	printf("������������Ҫ���������\n");
	int x = 0, y = 0;
	scanf("%d %d",&x,&y);
	printf("%d\n",p(x,y));
}
int main()
{
	int input = 1;
	while(input)
	{
		menu();
		printf("��������Ҫ���еĲ�����Ӧ�ı�ţ�\n");
		scanf("%d",&input); 
		switch(input)
		{
			case 1:
				Cac(Add);break;
			case 2:
				Cac(Sub);break;
			case 3:
				Cac(Mul);break;
			case 4:
				Cac(Div);break;
			case 0:
				printf("�˳�\n");
				return 0;
			default:
				printf("�����������������\n");
		}
	}
	return 0;
}
