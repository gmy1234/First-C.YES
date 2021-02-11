#include"SeqlList.h"

//��������
void CheckCapacity(SeqList1* pt)
{
  
    SeqListDataType* str=(SeqListDataType*)realloc(pt->data,sizeof(SeqListDataType)*(pt->capacity+2));
    if (str == NULL)
    {
	perror("CheckCapacity");
	return ;
    }
    pt->data=str;
    pt->capacity+=2;
}

//��ʼ��
void SeqListInit(SeqList1* pt)
{
	
	pt->data=(SeqListDataType*)malloc(sizeof(SeqListDataType) * 4);
	if (pt->data == NULL)
	{
	    return ;
	}
	pt->size=0;
	pt->capacity=4;
        
}

//����
void SeqListDestory(SeqList1* pt)
{
    free(pt->data);
    pt->data=NULL;
}

//ͷ��
void SeqListPushFront(SeqList1* pt, SeqListDataType x)
{
    if (pt->size == pt->capacity)
    {
	CheckCapacity(pt);

    }

    memmove(pt->data + 1, pt->data, pt->size * sizeof(SeqListDataType));
    pt->size++;
    pt->data[0] = x;
}

//ͷɾ
void SeqListEraseFront(SeqList1* pt)
{
    pt->data[0]=0;

    memmove(pt->data,pt->data+1,(pt->size-1)*sizeof(SeqListDataType));
    pt->size--;
}

//β�壺
void SeqListPushBack(SeqList1* pt, SeqListDataType x)
{
    if (pt->size == pt->capacity)
    {
	//����������
	CheckCapacity(pt);
    }
    
    pt->data[pt->size]=x;
    pt->size++;

}

//β��ɾ��
void SeqListEraseBack(SeqList1* pt)
{
    pt->data[pt->size - 1] = 0;
    pt->size--;
}

//��Posλ�ò���
void SeqListPushPos(SeqList1* pt,SeqListDataType Pos, SeqListDataType x)
{
   
    if (pt->size == pt->capacity)
    {
	CheckCapacity(pt);

    }
    memmove(pt->data+Pos,pt->data+Pos-1,sizeof(SeqListDataType)*(pt->size-(Pos-1)));
    pt->data[Pos-1]=x;
    pt->size++;
}

//��Posλ��ɾ��
void SeqListErasePos(SeqList1* pt, SeqListDataType Pos)
{
    pt->data[Pos-1]=0;
    memmove(pt->data+Pos-1,pt->data+Pos,sizeof(SeqListDataType)*(pt->size-Pos));
    pt->size--;
}
//���ң�
int SeqListSearch(SeqList1* pt, SeqListDataType x)
{
   //��ͨ�����ǵ��ж��Ƿ�Խ�磺
   /*int i=0;
   for (i = 0; i < pt->size; i++)
   {
       if((x)==pt->data[i])
	{
	    return (i+1);
	}
	
	
   }
   return 0;*/

   // �Ӻ���ǰ���ң�
   int i=pt->size;
    while(pt->data[i]!=x)
	--i;
    return i+1;

}

//��ӡ
void PrintfSeqList(SeqList1* pt)
{
    int i=0;
    for(i=0;i<pt->size;i++)
    { 
	printf("%d ",pt->data[i]);
    }
    printf("\n");
}

