#include<stdio.h>
#include<math.h>
/*ģ�������*/ 
int main()
{
	int i=1,n=1;
	double number1,number2,number;
	while(i)
	{
		printf("������һ�����봦���ֵ:");
		scanf("%lf",&number1);
		printf("������һ����:(����1����ʹ�üӣ�����2����ʹ�ü�������3����ʹ�óˣ�����4����ʹ�ó���������5����ʹ��ƽ����������6����ʹ��ȡ����������7����ʹ��ȡ�ٷ���,����0�����˳�)");
		scanf("%d",&n);
		if(n<=4)
		{
			printf("������һ�����봦���ֵ:");
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
			printf("���Ϊ%f%%",number);
			break;
			}
			default:
			break;
			}
		}
		if(n!=7)
		{
			printf("���%f",number);
		}
	printf("�Ƿ�Ҫ����ʹ�ü�����,��������1����������0��");
	scanf("%d",&i);
	}
	return 0;
}	
