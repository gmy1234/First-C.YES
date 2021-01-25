#include<stdio.h>
int main()
{
	int i, j, n, h;
	int arr[5][5] = { 0 };
	for (i = 0; i < 5; i++)
	{
		arr[i][i] = 1;
		arr[i][0] = 1;
	}

	for (i =2 ; i < 5; i++)
	{
		for (j =1 ; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
		printf("\n");
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}