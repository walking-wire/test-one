#include<stdio.h>
int main()
{
	int l,d,s,o;
	l=0;d=0;s=0;o=0;
	char c;

	printf("������һ���ַ�,�Իس�������\n");
	while((c=getchar())!='\n')
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
		l++;
		else	if(c>='0'&&c<='9')
			d++;
			else	if(c==' ')
				s++;
				else 
				o++;
	printf("�����ַ��к�%d����ĸ,%d������,%d���ո�,%d�������ַ�",l,d,s,o);
return 0;
}