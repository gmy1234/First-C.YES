#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>


typedef struct ListStack {
	int data;
	ListStack* next;
}ListStack;

void InitLstack(ListStack** s)
{
	*s = NULL;
}

//开辟
ListStack* BuyNewnode(int x)
{
	ListStack* newNode = (ListStack*)malloc(sizeof(ListStack));
	if (newNode == NULL)
	{
		exit(-1);
	}
	newNode->next = NULL;
	newNode->data = x;
	return newNode;
}

void lstackPush(ListStack** s, int x)
{
	ListStack* newNode = (ListStack*)malloc(sizeof(ListStack));
	if (newNode == NULL)
	{
		exit(-1);
	}

	newNode->data = x;
	newNode->next = *s;
	*s = newNode;

}

void stcakPop(ListStack** s)
{
	if (*s == NULL)
	{
		printf("空栈");
		return;
	}

	ListStack* cur = (*s);
	(*s) = (*s)->next;
	free(cur);
	return;

}
int main()
{
	ListStack* top = NULL;
	InitLstack(&top);

	int number = 0;
	printf("请输入整数序列：\n");
	while (number != -1)
	{
		scanf("%d", &number);
		if (number != -1)
			lstackPush(&top, number);
	}

	printf("出栈前栈顶元素为：%d\n", top->data);
	stcakPop(&top);
	printf("出站后栈顶元素为：%d\n", top->data);

	return 0;
}