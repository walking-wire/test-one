/*�ж�101-200֮���ж��ٸ��������������������*/
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
