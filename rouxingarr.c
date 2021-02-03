#include<stdio.h>
#include<stdlib.h>


struct Tt {
	int n;
	int arr[];//柔性数组：
};

struct S {
	int n;
	int* arr;//
};

int main()
{
	//柔性数组开辟一次空间就行
	int i=0;
	struct Tt* s=(struct Tt* )malloc(sizeof(struct Tt) +10*sizeof(int));
	if(s==NULL)
		return 0;	
	else
	{
	s->n = 20;
	for (i = 0; i < 10; i++)
	{
		s->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", s->arr[i]);
	}
	free(s);
	s= NULL;
	}	

	//非柔性数组：
	int i = 0;
	struct S* p=(int*)mallo(sizeof(struct S));
	if (p == NULL)
	{
		printf("开辟失败：");
	}

	else
	{
		p->n = 100;
		p->arr = (int*)malloc(sizeof(int) * 5);
		if (p->arr == NULL)
			printf("开辟失败;");
		else
		{
			for (i = 0; i < 5; i++)
			{
				p->arr[i] = i;
				printf("%d ", p->arr[i]);
			}
			free(p->arr);
			p->arr = NULL;
			free(p);
			p = NULL;
		}

	}

	return 0;
}