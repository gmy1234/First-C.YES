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

//����ʱ�����µÿռ䣺
SListNode* BuySList(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//ͷ�壺
void SListPushFront(SListNode** pphead, SListDataType x)
{

		SListNode* newNode=BuySList(x);
		newNode->next=*pphead;	
		*pphead=newNode;
	
}
//
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


//ͷɾ��
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

//βɾ
void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return ;
	}
	else if ((*pphead)->next == NULL)
	{
		
		free(*pphead);
		(*pphead)=NULL;
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


//����
SListNode* SListPos(SListNode* phead, SListDataType x)
{
	if(phead==NULL)
		return NULL;
	SListNode* cur=phead;
	SListNode* Pos = NULL;
	while (cur != NULL)
	{
		if(cur->data==x)
			return cur;
		cur=cur->next;
	}
	return NULL;
}


//��Posλ�ú�߲���x
void SListInsterAfter(SListNode** Pos, SListDataType x)
{
	SListNode* cur=*Pos;
	SListNode* newNode=BuySList(x);
	newNode->next=(*Pos)->next;
	(*Pos)->next=newNode;

}


//ɾ��Posλ�ú��һ���Ľڵ㣺
void SListErasePos(SListNode** Pos)
{
	SListNode* cur=*Pos;
	SListNode* Next=cur->next;
	SListNode* Nextnext=Next->next;
	cur->next=Nextnext;
	Next->next=NULL;
	free(Next);

}