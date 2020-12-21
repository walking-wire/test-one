#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	/*指向数字的指针*/
	int a = 0;
	int *ip = &a;
	printf("%p,%d",ip,*ip);
	printf("\n");
	/*指向字符的指针*/
	char word = 'a';
	char*cp = &word;
	printf("%p,%c",cp,*cp);
	printf("\n");
	/*指向数字数组的指针*/
	double arr[3] = { 1.3, 2.34, 0.6};
	double *arrp = arr;
	int i = 0;
	for( i = 0; i< 3; i++)
	{
		printf("%.2f ",*arrp);
		arrp++;
	}
	printf("\n");
	/*指向字符数组的指针*/
	char str[10] = "hello";
	char *ccp = str;
	printf("%s",ccp);
	printf("\n");
	/*指向字符串的指针*/
	const char *cccp = "hellp";//注意const 
	printf("%s,%c",cccp,*cccp);
	printf("\n");
	/*指向二维数字类型的数组的指针*/
	int arr2[3][4] = {{1,2,3,4},{5,6,7,8},{9,0,10,11}};
	int (*ip2)[4] = arr2;//ip2为指向二维数组的指针 
	for(i = 0; i< 12; i++)
	{
		printf("%d ",*(*ip2+i));//*p为含4个int型的数组， 
	}
	printf("\t");
	int *ip22[3] = {*arr2,*(arr2+1),*(arr2+2)};//ip22为含3个指向整型的指针的数组 
	for(i = 0; i< 3; i++)
	{
		int j = 0;
		for( j = 0; j< 4; j++)
		{
			printf("%d ",*(ip22[i]+j));
		}
	}
	printf("\n");
	/*指向字符型二维数组的指针*/
	char str2[10][10] = {"apple","fuck", "sum"};
	char (*cp2)[10] =str2;//cp2为指向二维字符数组中的第一个一维字符数组的指针 
	for(i = 0; i< 3; i++)
	{
		printf("%s ",*cp2);
		cp2++;
	}
	printf("\n");
	char *ccp2[10] = {*str2,*(str2+1),*(str2+2)};//ccp2为含有10个字符指针（指向str2中每个一维数组的第一个字符）的数组 
	for(i = 0; i< 3; i++)
	{
		printf("%s ",*(str2+i));
		printf("%s ",ccp2[i]);
	}
	return 0;
}
