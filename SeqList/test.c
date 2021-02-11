#include"SeqlList.h"


void TestSeqList()
{
	SeqList1 s;
	SeqListInit(&s);
	SeqListPushFront(&s,1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 6);
	//尾插
	SeqListPushBack(&s,7);
	//尾删
	//SeqListEraseBack(&s);
	//头删
	//SeqListEraseFront(&s);
	//在3的位置插入
	//SeqListPushPos(&s,3,43);
	//在3的位置删除
	SeqListErasePos(&s,3);
	//打印
	PrintfSeqList(&s);

	//查找：
	int x=0;
	printf("请输入你要查找的数字：->");
	scanf("%d", &x);

	int POS=SeqListSearch(&s,x);
	if (POS == 0)
	{
	    printf("无此数");
	}
	else
	printf("位置在:%d\n",POS);
	
	
	SeqListDestory(&s);

}
int main()
{
	TestSeqList();
	    
	return 0;
}