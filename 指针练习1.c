#include<stdio.h>
/*用函数和指针完成下述程序功能：有两个整数a和b，由用户输入1,2或3。如输入1，程序就给出a和b中大者，输入2，就给出a和b中小者，输入3，则求a与b之和*/
int func(int *a, int *b,int number)
{
	int max = 0, min = 0;
	if(*a >= *b)
	{
		max = *a;
		min = *b;
	}
	else
	{
		max = *b;
		min = *a;
	}
	switch(number)
	{
		case 1:
		return max;break;
		case 2:
		return min;break;
		case 3:
		return *a+*b;break;
		default:
		return NULL;
	}
}
int main()
{
	int x,y,num;
	printf("请输入您想要处理的两数：");
	scanf("%d,%d",&x,&y);
	printf("请输入您想对这两数做出的运算编号:");
	scanf("%d",&num);
	printf("%d",func(&x,&y,num));
	return 0;
}
