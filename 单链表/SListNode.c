#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef int SListDataType;

typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;

}SListNode;


//增  删：
//尾插
void SListPushBack(SListNode** pphead, SListDataType x);
// 头插
void SListPushFront(SListNode** pphead, SListDataType x);

void SListPrint(SListNode* phead);


int main()
{
	SListNode* phead = NULL;

	SListPushFront(&phead, 1);
	SListPushFront(&phead, 0);
	SListPushBack(&phead, 2);
	SListPrint(phead);


	return 0;
}


void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);

		cur = cur->next;
	}
	printf("NULL\n");
}

//插入时开辟新得空间：
SListNode* BuySList(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//头插：
void SListPushFront(SListNode** pphead, SListDataType x)
{
	// 1. 没有节点
	if (*pphead == NULL)
	{
		*pphead = BuySList(x);
	}
	//2. 有节点：
	else
	{
		SListNode* cur = *pphead;

		*pphead = BuySList(x);
		(*pphead)->next = cur;
	}
}
void SListPushBack(SListNode** pphead, SListDataType x)
{
	if (*pphead == NULL)
	{
		*pphead = BuySList(x);
	}
	else
	{
		SListNode* cur = *pphead;
		SListNode* prve = *pphead;
		while (cur != NULL)
		{
			prve = cur;
			cur = cur->next;
		}
		cur = BuySList(x);
		prve->next = cur;

	}
}

