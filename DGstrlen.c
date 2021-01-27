#include<stdio.h>
#include<assert.h>
int my_strlen(const char* s1)
{
	assert(s1 != NULL);
		if (*s1 == '\0')
			return 0;
		else
			return 1 + my_strlen(s1 + 1);

}
int main()
{
	char c[] = "abcdfeg";
	int ret=my_strlen(c1);
	printf("%d\n", ret);
	return 0;
}