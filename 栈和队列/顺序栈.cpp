#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAXSIZE 10

//˳��ջ

typedef int stackDataType;
typedef struct stackNode {
	stackDataType* top;
	stackDataType* base;
	stackDataType  maxSize;
}stackNode;

//��--��ջ
void stackPush(stackNode* s, stackDataType x);

//ɾ
//��ջ
void stackPop(stackNode* s);

//��ʼ�� 
void InitStack(stackNode* s);
//��ӡ
void stackPrint(stackNode* s);

//��ȡջ�������ݡ�
stackDataType getTop(stackNode* s);

//����ջ
void destroyStack(stackNode* s);
//���
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

//��ջ��
void stackPush(stackNode* s, stackDataType x)
{
	if (s->top - s->base == s->maxSize)
	{
		printf("ջ�Ѿ�����\n");
		return;
	}
	*(s->top) = x;
	s->top++;

}
//��ջ
void stackPop(stackNode* s)
{
	if (s->top == s->base)
	{
		printf("ջΪ��\n");
		return;
	}
	*(s->top) = 0;
	s->top--;
}

//��ӡ  ȡ��ջԪ��
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

//ȡջ��Ԫ��
stackDataType getTop(stackNode* s)
{
	if (s->base != s->top)
	{

		return *(s->top - 1);
	}

}

//����ջ
void destroyStack(stackNode* s)
{
	clearStack(s);
	free(s->base);
	return;
}
//���ջ
void clearStack(stackNode* s)
{
	s->top = s->base;
	return;
}