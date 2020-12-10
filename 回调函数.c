#include<stdio.h>
/*简易计算器*/
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
	printf("请输入两个需要处理的数：\n");
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
		printf("请输入需要进行的操作对应的编号：\n");
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
				printf("退出\n");
				return 0;
			default:
				printf("输入错误，请重新输入\n");
		}
	}
	return 0;
}
