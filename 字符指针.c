#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	/*ָ�����ֵ�ָ��*/
	int a = 0;
	int *ip = &a;
	printf("%p,%d",ip,*ip);
	printf("\n");
	/*ָ���ַ���ָ��*/
	char word = 'a';
	char*cp = &word;
	printf("%p,%c",cp,*cp);
	printf("\n");
	/*ָ�����������ָ��*/
	double arr[3] = { 1.3, 2.34, 0.6};
	double *arrp = arr;
	int i = 0;
	for( i = 0; i< 3; i++)
	{
		printf("%.2f ",*arrp);
		arrp++;
	}
	printf("\n");
	/*ָ���ַ������ָ��*/
	char str[10] = "hello";
	char *ccp = str;
	printf("%s",ccp);
	printf("\n");
	/*ָ���ַ�����ָ��*/
	const char *cccp = "hellp";//ע��const 
	printf("%s,%c",cccp,*cccp);
	printf("\n");
	/*ָ���ά�������͵������ָ��*/
	int arr2[3][4] = {{1,2,3,4},{5,6,7,8},{9,0,10,11}};
	int (*ip2)[4] = arr2;//ip2Ϊָ���ά�����ָ�� 
	for(i = 0; i< 12; i++)
	{
		printf("%d ",*(*ip2+i));//*pΪ��4��int�͵����飬 
	}
	printf("\t");
	int *ip22[3] = {*arr2,*(arr2+1),*(arr2+2)};//ip22Ϊ��3��ָ�����͵�ָ������� 
	for(i = 0; i< 3; i++)
	{
		int j = 0;
		for( j = 0; j< 4; j++)
		{
			printf("%d ",*(ip22[i]+j));
		}
	}
	printf("\n");
	/*ָ���ַ��Ͷ�ά�����ָ��*/
	char str2[10][10] = {"apple","fuck", "sum"};
	char (*cp2)[10] =str2;//cp2Ϊָ���ά�ַ������еĵ�һ��һά�ַ������ָ�� 
	for(i = 0; i< 3; i++)
	{
		printf("%s ",*cp2);
		cp2++;
	}
	printf("\n");
	char *ccp2[10] = {*str2,*(str2+1),*(str2+2)};//ccp2Ϊ����10���ַ�ָ�루ָ��str2��ÿ��һά����ĵ�һ���ַ��������� 
	for(i = 0; i< 3; i++)
	{
		printf("%s ",*(str2+i));
		printf("%s ",ccp2[i]);
	}
	return 0;
}
