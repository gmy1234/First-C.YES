#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strncat(char* dest, char* sourse, int count)
{
	assert(dest && sourse);
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (count > 0)
	{
		*dest++ = *sourse++;
		count--;
	}

	if (count == 0)
		*(dest) = '\0';
	return ret;

}
int main()
{
	char c1[10] = "abcd\0xxx";
	char c2[] = "qwerty";

	strncat(c1, c2, 2);
	printf("%s\n", c1);

	char cc1[10] = "abcd\0xxx";
	char cc2[] = "qwerty";
	my_strncat(cc1, cc2, 2);
	printf("ģ�⣺%s\n", cc1);


	return 0;
}
