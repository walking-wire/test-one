#include<stdio.h>
/*Caesar½âÃÜ*/
int main()
{
	int i = 0;
	char str[100];
	gets(str);
	while(str[i] != '\0')
	{
		if(str[i]>='a' && str[i]<='z')
		{
			str[i] = (char)((str[i] - 'a' - 3 + 26) % 26 + 'a');
		}
		else if(str[i]>='A' && str[i]<='Z')
		{
			str[i] = (char)((str[i] - 'A' - 3 + 26) % 26 + 'A');
		}
		i++;
	}
	puts(str);
	return 0;
}
