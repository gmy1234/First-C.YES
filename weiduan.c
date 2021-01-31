#include<stdio.h>
//Î»¶Î

struct A {
	char a : 3;
	char b : 4;
	char c : 5;
};

int main()
{
	printf("%d\n", sizeof(A));
	return 0;
}