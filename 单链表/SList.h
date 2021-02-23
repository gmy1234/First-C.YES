#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef int SListDataType;

typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;

}SListNode;


//Ôö  É¾£º
//Î²²å
void SListPushBack(SListNode** pphead,SListDataType x);
// Í·²å
void SListPushFront(SListNode** pphead, SListDataType x);

//wÎ²É¾
void SListPopBack(SListNode** pphead);
//Í·É¾
void SListPopFront(SListNode** pphead);




void SListPrint(SListNode* phead);

