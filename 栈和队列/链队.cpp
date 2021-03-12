#include<stdio.h>
#include<stdlib.h>

typedef int dataType;
typedef struct ListQueue {
	dataType data;
	ListQueue* next;
}ListQueue;

typedef struct S {
	ListQueue* rear;
	ListQueue* front;
}Queue;

//初始化
void InitQueue(Queue** q)
{
	(*q) = (Queue*)malloc(sizeof(Queue));
	if (*q == NULL)
		return;
	(*q)->front = NULL;
	(*q)->rear = NULL;

}
//队空
int Isempty(Queue* q)
{
	if (q->front == NULL && q->rear == NULL)
	{
		return 1;
	}
	else
		return 0;

}

void enQueue(Queue* q, dataType x)
{
	ListQueue* newNode = (ListQueue*)malloc(sizeof(ListQueue));
	if (newNode == NULL)
		return;
	newNode->data = x;
	newNode->next = NULL;
	//说明队空
	if (Isempty(q) == 1)
	{
		q->front = q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

//出队
int deQueue(Queue* q)
{
	if (Isempty(q) == 1)
	{
		printf("队空\n");
		exit(-1);
	}
	ListQueue* cur = q->front;
	//只有一个元素
	if (q->front == q->rear)
	{
		q->front = q->rear = NULL;

	}
	else
	{
		q->front = q->front->next;
	}
	int x = cur->data;
	free(cur);
	return x;
}

//取队头元素
int getTopQueue(Queue* q)
{
	if (Isempty(q) == 1)
	{
		printf("队空\n");
		exit(-1);
	}
	ListQueue* cur = q->front;
	return cur->data;

}
int main()
{
	Queue* q;
	InitQueue(&q);
	enQueue(q, 1);
	enQueue(q, 2);
	int c = deQueue(q);
	printf("%d\n", c);

	int x = getTopQueue(q);
	printf("队头元素为%d", x);

}