#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* a = (int*)malloc(10 * sizeof(int));
	if (a != NULL)
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			*(a + i) = i;
			printf("%d", *(a + i));
		}
	}
	free(a);  // 释放分配的内存
	a = NULL;// 指针指向空
	return 0;
}