#include<stdio.h>
#include<stdlib.h>


struct Tt {
	int n;
	int arr[];//�������飺
};

struct S {
	int n;
	int* arr;//
};

int main()
{
	//�������鿪��һ�οռ����
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

	//���������飺
	int i = 0;
	struct S* p=(int*)mallo(sizeof(struct S));
	if (p == NULL)
	{
		printf("����ʧ�ܣ�");
	}

	else
	{
		p->n = 100;
		p->arr = (int*)malloc(sizeof(int) * 5);
		if (p->arr == NULL)
			printf("����ʧ��;");
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