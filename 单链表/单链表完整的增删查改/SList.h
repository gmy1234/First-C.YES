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
void SListPushBack(SListNode** pphead,SListDataType x);
// 头插
void SListPushFront(SListNode** pphead, SListDataType x);

//w尾删
void SListPopBack(SListNode** pphead);
//头删
void SListPopFront(SListNode** pphead);

// 在查找POS
SListNode* SListPos(SListNode* phead,SListDataType x);

//在Pos位置后边插入节点：

void SListInsterAfter(SListNode** Pos,SListDataType x);

//在Pos位置删除节点
void SListErasePos(SListNode** Pos);


void SListPrint(SListNode* phead);

