#include<stdio.h>

//struct book
//{
//	char title[100];
//	char author[100];
//	double price;
//};
//
//int main()
//{
//	struct book s1 = {
//		"语文",
//		"阿佘",
//		22.5
//	};
//	printf("%s，%s",s1.title,s1.author);
//	return 0;
//}

//typedef struct kid//typedef结构体 
//{
//	char name[100];
//	int age;
//	double height;
//}kids;
//
//int main()//初始化结构体 
//{
//	kids kiki = {
//		"kiki",
//		18,
//		1.8
//	};
//	printf("%s",kiki.name);
//	return 0;
//}

//struct kid
//{
//	char name[100];
//	int age;
//	double height;
//}kiki;
//
//int main()//访问结构体元素 
//{
//	kiki.age = 18;
//	kiki.height = 1.8;
//	printf("%d",kiki.age);
//	return 0;
//}

typedef struct kid
{
	char name[100];
	int age;
	double height;
}kids;

//int main()//结构体数组 
//{
//	kids kidnaps[2] = {
//		{"kiki",18,1.8},
//		{"carsi",17,1.78}
//	};
//	int i = 0;
//	for(i = 0; i< 2; i++)
//	{
//		printf("第%d名孩子信息：姓名：%s,年龄：%d,身高：%.2f\n",i+1, kidnaps[i].name, kidnaps[i].age, kidnaps[i].height);
//	}
//	return 0;
//}

//int main()//取结构体中的数组元素 
//{
//	kids kidnaps = {
//		"kiki",
//		18
//	};
//	printf("%c",kidnaps.name[2]);
//	printf("\n");
//	printf("%f",kidnaps.height);
//	return 0;
//}

typedef struct book
{
	char name[100];
	char author[100];
	int price;
}library;

//int main()//结构体指针 
//{
//	library book1 = {
//		"春",
//		"朱自清",
//		23
//	};
//	library book2 = {
//		"修仙传",
//		"佚名",
//		100
//	};
//	struct book *p1;
//	p1 = &book1;
//	printf("%s ",p1->author);//结构体指针访问结构体元素 
//	return 0;
//}

int main()
{
	library book[3] = {
		{"春","朱自清",22.5},
		{"修仙传","佚名",30},
		{" ",30}
	};
	library *p;
	p = book;//p为结构体数组的首个数组的地址 
	int i = 0;
	for(i = 0; i< 3; i++)
	{
		printf("%s ",p->author);
		p++;
	}
}
