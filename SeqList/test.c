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
	//β��
	SeqListPushBack(&s,7);
	//βɾ
	//SeqListEraseBack(&s);
	//ͷɾ
	//SeqListEraseFront(&s);
	//��3��λ�ò���
	//SeqListPushPos(&s,3,43);
	//��3��λ��ɾ��
	SeqListErasePos(&s,3);
	//��ӡ
	PrintfSeqList(&s);

	//���ң�
	int x=0;
	printf("��������Ҫ���ҵ����֣�->");
	scanf("%d", &x);

	int POS=SeqListSearch(&s,x);
	if (POS == 0)
	{
	    printf("�޴���");
	}
	else
	printf("λ����:%d\n",POS);
	
	
	SeqListDestory(&s);

}
int main()
{
	TestSeqList();
	    
	return 0;
}