#include<stdio.h>
/* µœ÷strcat*/
int main()
{
	char arr1[6] = {"HELLO"};
	char arr2[6] = {"world"};
	int i = 0,sz1 = 0,sz2 = 0 ,sz = 0;
	sz1 = sizeof(arr1);
	sz2 = sizeof(arr2);
	sz = sz1+sz2-1;
	char str[sz];
	for(i=0;i<sz1-1;i++)
	{
		str[i] = arr1[i];
	}
	i = 0;
	for(i=0;i<sz2;i++)
	{
		str[i+sz2-1] = arr2[i];
	}
	printf("%s",str);
	return 0;
}
