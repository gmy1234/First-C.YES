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
	free(a);  // �ͷŷ�����ڴ�
	a = NULL;// ָ��ָ���
	return 0;
}