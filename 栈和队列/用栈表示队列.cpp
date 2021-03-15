#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define Cacpcity 10

//栈的定义
typedef struct stack {
	int* stack;
	//栈的栈顶指针
	int top;
	//栈的最大容量
	int stackCacpcity;
}mystack;

//初始化
mystack* InitStack(int cacpcity);
//入栈
mystack* stackPush(mystack* myst, int x);
//出栈
void stackPop(mystack* myst);

//得到栈顶元素
int getTop(mystack* myst);
//判断栈空
int stackEmpty(mystack* myst);
//判断栈满
int stackFull(mystack* myst);



//双栈-----------------------------------------------

typedef struct {
	//元素压入输入栈，
	mystack* InStack;
	//在将十输入栈顶指针压入输出栈，改变顺序.
	mystack* OutStack;
}myQueue;

//队列初始化
myQueue* InitQueue();

//入输出栈
void queuePush(myQueue* myqu, int x);

//输入栈->输入栈
void insForOustack(myQueue* myqu);

//输出栈出栈
void OutStackPop(myQueue* myqu);

//得到输出栈的栈顶元素

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

	//输出栈出栈
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		arr[i] = getTopQueue(que);
		OutStackPop(que);
		printf("%d  ", arr[i]);
	}

	return 0;
}


// 算法

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

//是否栈空
int stackEmpty(mystack* myst)
{
	//栈空
	if (myst->top == 0)
	{
		printf("栈空,无法出栈\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

//判断栈满，栈满返回1，否则返回0
int stackFull(mystack* myst)
{
	if (myst->top == myst->stackCacpcity - 1)
	{
		printf("栈满,无法入栈\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

mystack* stackPush(mystack* myst, int x)
{
	//1.入栈，栈满的话停止入栈
	if (stackFull(myst))// 栈满  if（1）
	{
		exit(-1);
	}
	else
	{
		//入栈
		myst->stack[myst->top] = x;
		//栈指针+1
		myst->top++;
	}
	return myst;

}

void stackPop(mystack* myst)
{
	//1.判断栈空，栈空返回1
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
		//栈空
		exit(-1);
	}
	return myst->stack[myst->top - 1];
}


//-----------------准备完成-------------------------


//队列

myQueue* InitQueue()
{
	myQueue* newNode = (myQueue*)malloc(sizeof(myQueue*));
	assert(newNode);

	newNode->InStack = InitStack(Cacpcity);
	newNode->OutStack = InitStack(Cacpcity);

	return newNode;
}


//入输入栈
void queuePush(myQueue* myqu, int x)
{
	if (stackFull(myqu->InStack))
	{
		return;
	}
	stackPush(myqu->InStack, x);
}

//输入栈->输出栈
void insForOustack(myQueue* myqu)
{
	//1判断输入栈是否为空
	while (!stackEmpty(myqu->InStack))
	{
		//将输入栈栈顶元素压入到输出栈当中

		stackPush(myqu->OutStack, getTop(myqu->InStack));
		//栈顶指针移动。
		stackPop(myqu->InStack);
	}

}

//输出栈出栈
void OutStackPop(myQueue* myqu)
{
	if (stackEmpty(myqu->OutStack))
	{
		return;
	}

	stackPop(myqu->OutStack);
}

//得到栈顶元素
int getTopQueue(myQueue* myqu)
{
	if (stackEmpty(myqu->OutStack))
	{
		exit(-1);
	}

	return getTop(myqu->OutStack);
}