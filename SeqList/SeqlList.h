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

//˳����ʼ��
void SeqListInit(SeqList1* pt);

//˳�������
void SeqListDestory(SeqList1* pt);

//����
void CheckCapacity(SeqList1* pt);

//˳���β��
void SeqListPushBack(SeqList1* pt,SeqListDataType x);

//βɾ
void SeqListEraseBack(SeqList1* pt);

//˳���ͷ��
void SeqListPushFront(SeqList1* pt, SeqListDataType x);

//ͷɾ
void SeqListEraseFront(SeqList1* pt);

//��POS��λ�ò��룺
void SeqListPushPos(SeqList1* pt, SeqListDataType Pos,SeqListDataType x);

//��POSλ��ɾ����
void SeqListErasePos(SeqList1* pt, SeqListDataType Pos);

//˳������
int SeqListSearch(SeqList1* pt,SeqListDataType x);

//��ӡ
void PrintfSeqList(SeqList1* pt);




