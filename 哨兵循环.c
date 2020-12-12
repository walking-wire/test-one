#include<stdio.h>
int main()
{
	int l,d,s,o;
	l=0;d=0;s=0;o=0;
	char c;

	printf("请输入一行字符,以回车键结束\n");
	while((c=getchar())!='\n')
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
		l++;
		else	if(c>='0'&&c<='9')
			d++;
			else	if(c==' ')
				s++;
				else 
				o++;
	printf("该行字符中含%d个字母,%d个数字,%d个空格,%d个其他字符",l,d,s,o);
return 0;
}