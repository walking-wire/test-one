#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=1;a<=9;a++)
	{
	for(b=1;b<=9;b++)
	{c=a*b;
	if(a>=b)
	printf("%d*%d=%d\t",b,a,c);}
	if(a<b)
	printf("\n"); 
	}
return 0;
}
