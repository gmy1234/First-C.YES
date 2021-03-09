#include<stdio.h>
#include<stdlib.h>

typedef int dstackType;
typedef struct DS {
	dstackType top[2], bot[2];	//ջ��ָ���ջ��ָ��
	dstackType m;	//ջ�������
	dstackType* v;	//ջ����
}doubleStack;

//��ʼ�� 
void InitDouStack(doubleStack* s, dstackType x);
//��ջ
void douStackPush(doubleStack* s, dstackType x, int i);
//��ջ
int douStackPop(doubleStack* s, int i, int& n);
//i��ջ�Ƿ�Ϊ��
int Isempty(doubleStack* s, int i);
//i��ջ�Ƿ�Ϊ��
int Isfull(doubleStack* s);

//�õ�i��ջ��Ԫ��
int getTop(doubleStack* s, int i);

//����ջ
void destroyStack(doubleStack* s)
{

	free(s->v);
}
//���i��ջ
void clearStack(doubleStack* s, int i)
{
	if (i == 0)
	{
		s->bot[0] = s->top[0];
	}
	else
	{
		s->bot[1] = s->top[1];
	}
}


int main()
{
	doubleStack S;

	//��ʼ��
	InitDouStack(&S, 10);
	douStackPush(&S, 1, 0);
	douStackPush(&S, 2, 0);
	douStackPush(&S, 3, 0);
	douStackPush(&S, 9, 0);
	int n = douStackPop(&S, 0, n);
	printf("0�ų�ջ��Ԫ��Ϊ��%d\n", n);

	int top = getTop(&S, 0);
	printf("0��Ŀǰջ��Ԫ��Ϊ��%d\n", top);

	douStackPush(&S, 8, 1);
	douStackPush(&S, 7, 1);
	douStackPush(&S, 6, 1);
	douStackPush(&S, 5, 1);
	int n2 = douStackPop(&S, 1, n2);
	printf("1�ų�ջ��Ԫ��Ϊ��%d\n", n2);

	int top2 = getTop(&S, 1);
	printf("1��Ŀǰջ��Ԫ��Ϊ��%d\n", top2);

	destroyStack(&S);

	return 0;
}

//��ʼ��
void InitDouStack(doubleStack* s, dstackType x)
{
	s->m = x;
	s->v = (dstackType*)malloc(sizeof(int) * 2 * x);
	if (s->v == NULL)
		return;
	s->bot[1] = s->top[1] = x;
	s->bot[0] = s->top[0] = -1;

}

//�ж�i��ջ�Ƿ��
int Isempty(doubleStack* s, int i)
{
	if (s->top[i] == -1)
	{
		printf("ջΪ��\n");
		return 1;
	}
	else
		return 0;
}

int Isfull(doubleStack* s)
{
	if ((s->top[0]) == s->top[1] - 1)
	{
		printf("ջ��\n");
		return 0;
	}
	else
		return 1;


}

//i��ջ��ջ
void douStackPush(doubleStack* s, dstackType x, int i)
{
	if (Isfull(s) == 0)
	{
		return;
	}
	if (i == 0)
	{
		s->top[0]++;
		s->v[s->top[0]] = x;
	}
	else
	{
		s->top[1]--;
		s->v[s->top[1]] = x;
	}

}

//i��ջ��ջ
int douStackPop(doubleStack* s, int i, int& n)
{
	if (Isempty(s, i) == 1)
	{
		return 0;
	}

	if (i == 0)
	{
		n = s->v[s->top[0]];
		s->top[0]--;
	}
	else
	{
		n = s->v[s->top[1]];
		s->top[1]++;
	}
	return n;
}


int getTop(doubleStack* s, int i)
{
	if (Isempty(s, i) == 1)
		return 0;

	return (s->v[s->top[i]]);
}