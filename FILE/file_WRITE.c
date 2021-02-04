#include<stdio.h>

int main()
{
	FILE* ptw = fopen("test11.txt", "w");
	if (ptw != NULL);
	{
		fputc('c', ptw); 
		fputc('d', ptw);

		fclose(ptw);
		ptw = NULL;	 
	}

	return 0;
}