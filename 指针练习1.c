#include<stdio.h>
/*�ú�����ָ��������������ܣ�����������a��b�����û�����1,2��3��������1������͸���a��b�д��ߣ�����2���͸���a��b��С�ߣ�����3������a��b֮��*/
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
	printf("����������Ҫ�����������");
	scanf("%d,%d",&x,&y);
	printf("�����������������������������:");
	scanf("%d",&num);
	printf("%d",func(&x,&y,num));
	return 0;
}
