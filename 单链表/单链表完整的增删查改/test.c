#include"SList.h"


void test()
{
	SListNode* phead = NULL;
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPrint(phead);
}

void test1()
{
	SListNode* phead = NULL;
	//SListPushFront(&phead, 9);
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 0);
	SListPushBack(&phead, 2);
	SListPrint(phead);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 5);
	SListPrint(phead);

	SListNode* Pos = SListPos(phead, 3);
	SListInsterAfter(&Pos, 4);
	SListPrint(phead);

	//PosÎ»ÖÃÉ¾³ý
	SListErasePos(&Pos);
	SListPrint(phead);
}
void test2()
{
	
}
int main()
{
	//test();

	test1();
	test2();
	return 0;
}