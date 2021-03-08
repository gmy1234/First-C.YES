#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAXSIZE 10

//顺序栈

typedef int stackDataType;
typedef struct stackNode {
	stackDataType* top;
	stackDataType* base;
	stackDataType  maxSize;
}stackNode;

//增--入栈
void stackPush(stackNode* s, stackDataType x);

//删
//出栈
void stackPop(stackNode* s);

//初始化 
void InitStack(stackNode* s);
//打印
void stackPrint(stackNode* s);

//获取栈顶的数据。
stackDataType getTop(stackNode* s);

//销毁栈
void destroyStack(stackNode* s);
//清空
void clearStack(stackNode* s);


void test()
{
	stackNode s;
	InitStack(&s);
	stackPush(&s, 0);
	stackPush(&s, 1);
	stackPush(&s, 2);
	stackPush(&s, 3);
	stackPush(&s, 4);
	stackPop(&s);
	stackPrint(&s);

	int x = getTop(&s);
	printf("%d", x);

	clearStack(&s);
	destroyStack(&s);

}
int main()
{
	test();
	return 0;
}



void InitStack(stackNode* s)
{
	s->base = (stackDataType*)malloc(sizeof(stackDataType) * MAXSIZE);
	if (s->base == NULL)
		return;

	s->maxSize = MAXSIZE;
	s->top = s->base;

}

//入栈：
void stackPush(stackNode* s, stackDataType x)
{
	if (s->top - s->base == s->maxSize)
	{
		printf("栈已经满了\n");
		return;
	}
	*(s->top) = x;
	s->top++;

}
//出栈
void stackPop(stackNode* s)
{
	if (s->top == s->base)
	{
		printf("栈为空\n");
		return;
	}
	*(s->top) = 0;
	s->top--;
}

//打印  取顶栈元素
void stackPrint(stackNode* s)
{

	int* head = s->top;
	while (s->base != s->top)
	{
		s->top--;
		printf("%d ", *(s->top));

		printf("\n");
	}
	s->top = head;
	return;
}

//取栈顶元素
stackDataType getTop(stackNode* s)
{
	if (s->base != s->top)
	{

		return *(s->top - 1);
	}

}

//销毁栈
void destroyStack(stackNode* s)
{
	clearStack(s);
	free(s->base);
	return;
}
//清空栈
void clearStack(stackNode* s)
{
	s->top = s->base;
	return;
}