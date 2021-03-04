#include<stdio.h>

void swap(int &a, int &b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void cg(int c, int d)
{
	int tmp = 0;
	tmp = c;
	c= d;
	d = tmp; 
}

int main()
{
	int a = 1, b = 2, c = 3, d = 4;
	printf("a = %d b = %d c = %d d = %d\n",a,b,c,d);
	swap(a,b);
	cg(c,d);
	printf("a = %d b = %d c = %d d = %d",a,b,c,d);
	return 0;
}
