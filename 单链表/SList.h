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
void SListPushBack(SListNode** pphead,SListDataType x);
// ͷ��
void SListPushFront(SListNode** pphead, SListDataType x);

//wβɾ
void SListPopBack(SListNode** pphead);
//ͷɾ
void SListPopFront(SListNode** pphead);




void SListPrint(SListNode* phead);

