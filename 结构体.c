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
//		"����",
//		"����",
//		22.5
//	};
//	printf("%s��%s",s1.title,s1.author);
//	return 0;
//}

//typedef struct kid//typedef�ṹ�� 
//{
//	char name[100];
//	int age;
//	double height;
//}kids;
//
//int main()//��ʼ���ṹ�� 
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
//int main()//���ʽṹ��Ԫ�� 
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

//int main()//�ṹ������ 
//{
//	kids kidnaps[2] = {
//		{"kiki",18,1.8},
//		{"carsi",17,1.78}
//	};
//	int i = 0;
//	for(i = 0; i< 2; i++)
//	{
//		printf("��%d��������Ϣ��������%s,���䣺%d,��ߣ�%.2f\n",i+1, kidnaps[i].name, kidnaps[i].age, kidnaps[i].height);
//	}
//	return 0;
//}

//int main()//ȡ�ṹ���е�����Ԫ�� 
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

//int main()//�ṹ��ָ�� 
//{
//	library book1 = {
//		"��",
//		"������",
//		23
//	};
//	library book2 = {
//		"���ɴ�",
//		"����",
//		100
//	};
//	struct book *p1;
//	p1 = &book1;
//	printf("%s ",p1->author);//�ṹ��ָ����ʽṹ��Ԫ�� 
//	return 0;
//}

int main()
{
	library book[3] = {
		{"��","������",22.5},
		{"���ɴ�","����",30},
		{" ",30}
	};
	library *p;
	p = book;//pΪ�ṹ��������׸�����ĵ�ַ 
	int i = 0;
	for(i = 0; i< 3; i++)
	{
		printf("%s ",p->author);
		p++;
	}
}
