#include<stdio.h>
#define str_size 100
/*实现strlen函数*/
int my_strlen(char str[str_size])
{
	int i = 0,length = 0;
	for(i=0;i<str_size;i++)
	{
		if(str[i] != '\0')
		{
			length++;
		}
	}
	return length;
}
int main()
{
	char str[str_size] = { 0 };
	gets(str);
	printf("字符串长度为%d",my_strlen(str));
	return 0;
}
