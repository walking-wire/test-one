#include<stdio.h>
int Double(int n)
{
	return n*n;
}
int down(int n)
{
	return n/2;
}
int main()
{
	int *p = NULL;
	int a = 10;
	p = &a;//ָ��ָ�򵥸����� 
	printf("%d\n",*p);
	int **p2 = &p;
	printf("%d",**p2);
	char arr[10] = {1,2,3,4,5,6,7,8,9,0};
	printf("\n");
	int*pp[1] = {&a};//ָ�����飬[]���ȼ�����*
	int i = 0;
		printf("%6d",(*pp[i]));
	char *ppp = NULL;
	ppp = arr;//����ָ��-ָ�������ָ�� 
	for(i = 0; i<10 ;i++)
	{
		printf("%6d",(ppp)[i]);
	}
	printf("\n");
	int (*pppp)(int n) = Double;//����ָ�� 
	printf("%d\n",pppp(a));
	int (*ppppp[2])(int n) = {Double, down};//����ָ������ 
	printf("%d\n",ppppp[1](a));
	int (*(*pppppp)[2])(int n) = &ppppp;//ָ����ָ�������ָ��
	printf("%d",(*(*pppppp)[1])(a));
	return 0;
}
