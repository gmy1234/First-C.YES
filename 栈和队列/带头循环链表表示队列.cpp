#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//带头结点的循环链表表示队列

typedef int dataType;
typedef struct Lqueue
{
	dataType data;
	Lqueue* next;
}Lqueue;
typedef struct Q {
	Lqueue* rear;
}Q;

void InitQueue(Q** s)
{
	(*s) = (Q*)malloc(sizeof(Q));
	assert((*s));
	(*s)->rear = (Lqueue*)malloc(sizeof(Lqueue));
	assert((*s)->rear);


	(*s)->rear->next = (*s)->rear;
}

void enQueue(Q* s, dataType x)
{
	Lqueue* newNode = (Lqueue*)malloc(sizeof(Lqueue));
	assert(newNode);
	newNode->data = x;

	Lqueue* head = s->rear->next;
	s->rear->next = newNode;
	newNode->next = head;
	s->rear = newNode;

}

void deQueue(Q* s, int& x)
{
	Lqueue* cur = s->rear->next;
	if (s->rear->next == s->rear)
	{
		printf("队列为空\n");
		exit(-1);
	}

	Lqueue* tail = s->rear;
	Lqueue* head = tail->next;
	Lqueue* first = head->next;
	head->next = first->next;

	x = first->data;

	free(first);
	return;

}
void clearQueue(Q* s)
{
	Lqueue* head = s->rear->next;
	Lqueue* cur = head->next;
	Lqueue* Next = cur->next;
	while (cur != head)
	{
		free(cur);
		cur = Next;
		Next = Next->next;
	}
}
int main()
{
	int arr[3] = { 0 };
	//初始化
	Q* s;
	InitQueue(&s);
	enQueue(s, 0);
	enQueue(s, 1);
	enQueue(s, 2);
	enQueue(s, 3);
	enQueue(s, 4);
	deQueue(s, arr[0]);
	deQueue(s, arr[1]);
	printf("%d,  %d", arr[0], arr[1]);

	return 0;
}