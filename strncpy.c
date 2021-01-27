#include<stdio.h>
#include<assert.h>
#include<string.h>

char* my_strncpy(char* s1, char* s2, int count)
{
	char* ret = s1;
	assert(s1 && s2);
	while (count--)
	{
		*s1++ = *s2++;

		if (*s2 == '\0')
		{
			*s1 = '\0';
		}

	}
	return s1;	
}

int main()
{
	char c1[] = "abcde";
	char c2[] = "qwer";
	my_strncpy(c1, c2, 3);
	printf("Ä£Äâ£º %s\n", c1);

	char cc1[] = "abcde";
	char cc2[] = "qwer";

	strncpy(cc1, cc2, 3);
	printf("¿âº¯Êý£º%s\n", cc1);
}
