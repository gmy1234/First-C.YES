#include"SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur=phead;
	while (cur != NULL)
	{
		printf("%d->",cur->data);

		cur=cur->next;
	}
	printf("NULL\n");
}

//插入时开辟新得空间：
SListNode* BuySList(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("开辟失败\n");
		exit(-1);
	}
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
		*pphead=BuySList(x);
	}
	//2. 有节点：
	else
	{
		SListNode* cur=*pphead;
		
		*pphead =BuySList(x);
		(*pphead)->next=cur;	
	}
}
void SListPushBack(SListNode** pphead, SListDataType x)
{
	if (*pphead == NULL)
	{
		*pphead=BuySList(x);
	}
	else
	{
		SListNode* cur=*pphead;
		SListNode* prve=*pphead;
		while (cur != NULL)
		{
				prve=cur;
				cur=cur->next;
		}
		cur=BuySList(x);
		prve->next=cur;
		
	}
}


//头删：
void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return ;
	}
	else 
	{
		SListNode* cur=*pphead;
		*pphead=(*pphead)->next;
		cur->next=NULL;
		free(cur);
	}
}

//尾删
void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return ;
	}
	else if ((*pphead)->next == NULL)
	{
		
		free(*pphead);
		(*pphead)->next=NULL;
	}
	else
	{
		SListNode* prve=*pphead;
		SListNode* tail=*pphead;
		while (tail->next != NULL)
		{
			prve=tail;
			tail=tail->next;
		}
		prve->next=NULL;
		free(tail);
	}
}