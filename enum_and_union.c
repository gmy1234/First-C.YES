#include<stdio.h>

enum A {
	male=4,
	famale
};
//�����壺

union Un {
	char a;
	int b;
};
int main()
{
	printf("%d ", male);
	printf("%d\n ", famale);
	printf("%d\n", siezof(male));

	union Un s;
	printf("%p\n", &(s.a));
	printf("%p\n", &(s.b));// ����һ���ڴ浥Ԫ��
	return 0;
}