/*判断101-200之间有多少个素数，并输出所有素数*/
#include<stdio.h>
#include<stdio.h>
int main()
{
	int n,i,time;
	for(n=101;n<=200;n++)
	{
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i == 0)
			{
				break;
			}
			else if(i = (int)(sqrt(n))) 
			{
				time +=1;
				printf("%d\t",n);
			}
		}
	}
	printf("\n %d",time); 
	return 0;
}
