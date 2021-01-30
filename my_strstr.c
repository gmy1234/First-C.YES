#include<stdio.h>
#include<assert.h>

char* my_strstr(char* p1, char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* ret = p1;
	char* s1 = NULL;
	char* s2 = NULL;
	char* cur = (char*)p1;
	if (*p1 == '\0')
		return ret;
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while (*s1 != '\0' && *s2 && (*s1 == *s2))
			s1++, s2++;
		if (*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}

	return NULL;
}
int main()
{
	char c1[] = "abcde";
	char c2[] = "bbc";
	char* ret = my_strstr(c1, c2);
	if (ret == NULL)
		printf("’“≤ªµΩ");
	else
		printf("%s\n", c2);
	return 0;
}