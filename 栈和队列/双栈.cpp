#include<stdio.h>
#include<stdlib.h>

typedef int dstackType;
typedef struct DS {
	dstackType top[2], bot[2];	//栈顶指针和栈底指针
	dstackType m;	//栈最大容量
	dstackType* v;	//栈数组
}doubleStack;

//初始化 
void InitDouStack(doubleStack* s, dstackType x);
//入栈
void douStackPush(doubleStack* s, dstackType x, int i);
//出栈
int douStackPop(doubleStack* s, int i, int& n);
//i号栈是否为空
int Isempty(doubleStack* s, int i);
//i号栈是否为满
int Isfull(doubleStack* s);

//得到i号栈顶元素
int getTop(doubleStack* s, int i);

//销毁栈
void destroyStack(doubleStack* s)
{

	free(s->v);
}
//清空i号栈
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

	//初始化
	InitDouStack(&S, 10);
	douStackPush(&S, 1, 0);
	douStackPush(&S, 2, 0);
	douStackPush(&S, 3, 0);
	douStackPush(&S, 9, 0);
	int n = douStackPop(&S, 0, n);
	printf("0号出栈的元素为：%d\n", n);

	int top = getTop(&S, 0);
	printf("0号目前栈顶元素为：%d\n", top);

	douStackPush(&S, 8, 1);
	douStackPush(&S, 7, 1);
	douStackPush(&S, 6, 1);
	douStackPush(&S, 5, 1);
	int n2 = douStackPop(&S, 1, n2);
	printf("1号出栈的元素为：%d\n", n2);

	int top2 = getTop(&S, 1);
	printf("1号目前栈顶元素为：%d\n", top2);

	destroyStack(&S);

	return 0;
}

//初始化
void InitDouStack(doubleStack* s, dstackType x)
{
	s->m = x;
	s->v = (dstackType*)malloc(sizeof(int) * 2 * x);
	if (s->v == NULL)
		return;
	s->bot[1] = s->top[1] = x;
	s->bot[0] = s->top[0] = -1;

}

//判断i号栈是否空
int Isempty(doubleStack* s, int i)
{
	if (s->top[i] == -1)
	{
		printf("栈为空\n");
		return 1;
	}
	else
		return 0;
}

int Isfull(doubleStack* s)
{
	if ((s->top[0]) == s->top[1] - 1)
	{
		printf("栈满\n");
		return 0;
	}
	else
		return 1;


}

//i号栈入栈
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

//i号栈出栈
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