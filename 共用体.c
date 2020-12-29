#include<stdio.h>

union un
{
	int n;
	char a[3];
}UN;

union unp
{
	int n;
	char a[5];
}UNP;

union us
{
	double n;
	char a[6];
	int i;
}US;

int main()
{
	printf("%d %d %d",sizeof(UN),sizeof(UNP),sizeof(US));
	return 0;
}
