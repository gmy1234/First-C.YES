#include<stdio.h>
#include<stdlib.h>

#define max 20
typedef int dataType;
typedef struct queue {
	dataType front;
	dataType rear;
	dataType* base;
}queue;

//初始化
void initQueue(queue* Q)
{
	Q->base = (dataType*)malloc(sizeof(dataType) * max);
	if (Q == NULL)
		return;
	Q->front = 0;
	Q->rear = 0;
}

//入队
void queueEnter(queue* Q, dataType x, int* flag)
{

	if (Q->front == Q->rear && *flag == 1)
	{
		printf("队满\n");
		return;
	}
	Q->base[Q->rear] = x;
	*flag = 1;
	Q->rear = (Q->rear + 1) % max;
}

//出队
void deQueue(queue* Q, int& x, int* flag)
{
	if (Q->front == Q->rear && *flag == 0)
	{
		printf("队空\n");
		return;
	}
	x = Q->base[Q->front];
	Q->front = (Q->front + 1) % max;
	*flag = 0;
}

//取队头的元素
dataType getTop(queue* Q, int* flag)
{
	if (Q->front == Q->rear && *flag == 0)
	{
		printf("队空\n");
		return 0;
	}
	return Q->base[Q->front];
}

//获取队列长度
int getQueueLength(queue* Q)
{
	return (Q->rear - Q->front + max) % max;
}

int main()
{
	queue Q;
	int x = 0;
	int f = 9;
	int* flag = &f;
	initQueue(&Q);
	queueEnter(&Q, 3, flag);
	queueEnter(&Q, 4, flag);
	queueEnter(&Q, 6, flag);
	queueEnter(&Q, 5, flag);
	queueEnter(&Q, 7, flag);
	deQueue(&Q, x, flag);
	int c = getTop(&Q, flag);
	printf("%d\n", c);

	printf("队列长度为:%d \n", getQueueLength(&Q));

	return 0;
}