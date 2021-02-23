#include"SList.h"

int main()
{
	SListNode* phead=NULL;	

	SListPushFront(&phead,1);
	SListPushFront(&phead, 0);
	SListPushBack(&phead,2);
	SListPrint(phead);
	
	SListPopFront(&phead);
	SListPrint(phead);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	//SListPopBack(&phead);
	SListPrint(phead);
	return 0;
}