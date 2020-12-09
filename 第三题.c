#include<stdio.h>
#include<math.h>
/*模拟计算器*/ 
int main()
{
	int i=1,n=1;
	double number1,number2,number;
	while(i)
	{
		printf("请输入一个你想处理的值:");
		scanf("%lf",&number1);
		printf("请输入一个数:(输入1代表使用加，输入2代表使用减，输入3代表使用乘，输入4代表使用除法，输入5代表使用平方根，输入6代表使用取倒数，输入7代表使用取百分数,输入0代表退出)");
		scanf("%d",&n);
		if(n<=4)
		{
			printf("请输入一个你想处理的值:");
			scanf("%lf",&number2);
			switch (n)
			{
				case 1:
				number = number1 + number2;break;
				case 2:
				number = number1 - number2;break;
				case 3:
				number = number1 * number2;break;
				case 4:
				number = number1 / number2;break;
				default:
					break;
			}
		}
		if(n>4)
		{
			switch (n)
			{
			case 5:
			number = sqrt(number1);break;
			case 6:
			number = 1/number1;break; 
			case 7:
			{
			number = 100*number1;
			printf("结果为%f%%",number);
			break;
			}
			default:
			break;
			}
		}
		if(n!=7)
		{
			printf("结果%f",number);
		}
	printf("是否要继续使用计算器,是则输入1，否则输入0：");
	scanf("%d",&i);
	}
	return 0;
}	
