#include<stdio.h>


struct stu {
	int a;
	char b;
	double c;
};
void pr1(struct stu A)
{
	printf("%d\n", A.a);
}
void pr2(struct stu* Q)
{
	printf("%d\t%c\t%lf\n", Q->a, Q->b, Q->c);
}
int main()
{
	struct stu s = { 1,'c',3.14 };
	pr1(s);
	pr2(&s);
	return 0;
}