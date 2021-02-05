#include<stdio.h>

int main()
{
	char T[20] = { 0 };
	FILE* ptr = fopen("test.txt", "r");
	if (ptr == NULL)
	{
		perror("hh");
	}
	else
	{
		fgets(T, 5,ptr);
		printf("%s", T);

		fgets("heihei", 7, ptr);
		puts(T);
		//╧ь╠унд╪Ч
		fclose(ptr);
		ptr = NULL;
	}
	return 0;
}