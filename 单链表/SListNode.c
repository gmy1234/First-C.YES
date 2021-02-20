#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef int SListDataType;

typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;

}SListNode;


//��  ɾ��
//β��
void SListPushBack(SListNode** pphead, SListDataType x);
// ͷ��
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

//����ʱ�����µÿռ䣺
SListNode* BuySList(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//ͷ�壺
void SListPushFront(SListNode** pphead, SListDataType x)
{
	// 1. û�нڵ�
	if (*pphead == NULL)
	{
		*pphead = BuySList(x);
	}
	//2. �нڵ㣺
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

