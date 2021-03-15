#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define Cacpcity 10

//ջ�Ķ���
typedef struct stack {
	int* stack;
	//ջ��ջ��ָ��
	int top;
	//ջ���������
	int stackCacpcity;
}mystack;

//��ʼ��
mystack* InitStack(int cacpcity);
//��ջ
mystack* stackPush(mystack* myst, int x);
//��ջ
void stackPop(mystack* myst);

//�õ�ջ��Ԫ��
int getTop(mystack* myst);
//�ж�ջ��
int stackEmpty(mystack* myst);
//�ж�ջ��
int stackFull(mystack* myst);



//˫ջ-----------------------------------------------

typedef struct {
	//Ԫ��ѹ������ջ��
	mystack* InStack;
	//�ڽ�ʮ����ջ��ָ��ѹ�����ջ���ı�˳��.
	mystack* OutStack;
}myQueue;

//���г�ʼ��
myQueue* InitQueue();

//�����ջ
void queuePush(myQueue* myqu, int x);

//����ջ->����ջ
void insForOustack(myQueue* myqu);

//���ջ��ջ
void OutStackPop(myQueue* myqu);

//�õ����ջ��ջ��Ԫ��

int getTopQueue(myQueue* myqu);



int main()
{

	myQueue* que;
	que = InitQueue();
	queuePush(que, 1);
	queuePush(que, 2);
	queuePush(que, 3);
	queuePush(que, 4);
	queuePush(que, 5);
	insForOustack(que);

	//���ջ��ջ
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		arr[i] = getTopQueue(que);
		OutStackPop(que);
		printf("%d  ", arr[i]);
	}

	return 0;
}


// �㷨

mystack* InitStack(int cacpcity)
{

	mystack* myst = (mystack*)malloc(sizeof(mystack));

	if (myst == NULL)
	{
		exit(-1);
	}
	myst->stack = (int*)malloc(sizeof(int) * cacpcity);
	myst->stackCacpcity = cacpcity;
	myst->top = 0;

	return myst;

}

//�Ƿ�ջ��
int stackEmpty(mystack* myst)
{
	//ջ��
	if (myst->top == 0)
	{
		printf("ջ��,�޷���ջ\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

//�ж�ջ����ջ������1�����򷵻�0
int stackFull(mystack* myst)
{
	if (myst->top == myst->stackCacpcity - 1)
	{
		printf("ջ��,�޷���ջ\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

mystack* stackPush(mystack* myst, int x)
{
	//1.��ջ��ջ���Ļ�ֹͣ��ջ
	if (stackFull(myst))// ջ��  if��1��
	{
		exit(-1);
	}
	else
	{
		//��ջ
		myst->stack[myst->top] = x;
		//ջָ��+1
		myst->top++;
	}
	return myst;

}

void stackPop(mystack* myst)
{
	//1.�ж�ջ�գ�ջ�շ���1
	if (stackFull(myst))
	{
		return;
	}
	myst->top--;
}

int getTop(mystack* myst)
{
	if (stackEmpty(myst))
	{
		//ջ��
		exit(-1);
	}
	return myst->stack[myst->top - 1];
}


//-----------------׼�����-------------------------


//����

myQueue* InitQueue()
{
	myQueue* newNode = (myQueue*)malloc(sizeof(myQueue*));
	assert(newNode);

	newNode->InStack = InitStack(Cacpcity);
	newNode->OutStack = InitStack(Cacpcity);

	return newNode;
}


//������ջ
void queuePush(myQueue* myqu, int x)
{
	if (stackFull(myqu->InStack))
	{
		return;
	}
	stackPush(myqu->InStack, x);
}

//����ջ->���ջ
void insForOustack(myQueue* myqu)
{
	//1�ж�����ջ�Ƿ�Ϊ��
	while (!stackEmpty(myqu->InStack))
	{
		//������ջջ��Ԫ��ѹ�뵽���ջ����

		stackPush(myqu->OutStack, getTop(myqu->InStack));
		//ջ��ָ���ƶ���
		stackPop(myqu->InStack);
	}

}

//���ջ��ջ
void OutStackPop(myQueue* myqu)
{
	if (stackEmpty(myqu->OutStack))
	{
		return;
	}

	stackPop(myqu->OutStack);
}

//�õ�ջ��Ԫ��
int getTopQueue(myQueue* myqu)
{
	if (stackEmpty(myqu->OutStack))
	{
		exit(-1);
	}

	return getTop(myqu->OutStack);
}