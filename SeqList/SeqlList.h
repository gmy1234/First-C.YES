#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma 4996

typedef int SeqListDataType;

typedef struct SeqList {
	SeqListDataType* data;
	SeqListDataType size;
	SeqListDataType capacity;
}SeqList1;

//顺序表初始化
void SeqListInit(SeqList1* pt);

//顺序表销毁
void SeqListDestory(SeqList1* pt);

//增容
void CheckCapacity(SeqList1* pt);

//顺序表尾插
void SeqListPushBack(SeqList1* pt,SeqListDataType x);

//尾删
void SeqListEraseBack(SeqList1* pt);

//顺序表头插
void SeqListPushFront(SeqList1* pt, SeqListDataType x);

//头删
void SeqListEraseFront(SeqList1* pt);

//在POS的位置插入：
void SeqListPushPos(SeqList1* pt, SeqListDataType Pos,SeqListDataType x);

//在POS位置删除：
void SeqListErasePos(SeqList1* pt, SeqListDataType Pos);

//顺序表查找
int SeqListSearch(SeqList1* pt,SeqListDataType x);

//打印
void PrintfSeqList(SeqList1* pt);




