#include<stdio.h>
#include<errno.h>

//int main()
//{
//	FILE* pfWrite = fopen("TEXT.txt", "w");//Сдw 
//	if(pfWrite == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	fputc('b', pfWrite);
//	fputc('i', pfWrite);
//	fputc('t', pfWrite);
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}

//int main()
//{
//	FILE *pfRead = fopen("text.txt", "r");
//	if(pfRead == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}

int main()
{
	int cg = fgetc(stdin);
	fputc(cg,stdout);
	return 0;
}
