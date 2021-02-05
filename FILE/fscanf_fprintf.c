#include<stdio.h>


//格式化的读写文件
	//sprintf 将数据打印到文件里

	//scanf将数据输出到屏幕上

typedef struct C {
	int a;
	char c;
	int d;
}D;

int main()
{
	D s = { 3,'c',0 };
	char ch[20] = { 0 };

	FILE* ptw = fopen("test1.txt", "w");
	if (ptw == NULL)
	{
		perror("hh");
	}
	else
	{
		fprintf(ptw, "%d %c %d", (s.a), (s.c), (s.d));
		printf("%d %c %d", (s.a), (s.c), (s.d));

		fclose(ptw);
		ptw = NULL;

	}

	FILE* ptr = fopen("test1.txt", "r");
	if (ptr == NULL)
	{
		perror("hh");
	}
	else
	{
		printf("\n");
		fscanf(ptr, "%d %c %d", &(s.a), &(s.c), &(s.d));
		printf("%d %c %d", s.a, s.c, s.d);


		fclose(ptr);
		ptr = NULL;
	}
	return 0;

}