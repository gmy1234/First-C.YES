#include<stdio.h>

int main()
{
	char T[20] = "ancdf";
	FILE* prw = fopen("test.txt", "w");
	if (prw == NULL)
	{
		perror("hh");
	}
	else
		//写一行
	{
		fgets(T, prw);
		fgets("gmy", prw);

		//关闭文件
		fclose(prw);
		prw = NULL;
	}
	return 0;
}