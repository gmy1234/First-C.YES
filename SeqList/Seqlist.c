#include"SeqlList.h"

//增加容量
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

//初始化
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

//销毁
void SeqListDestory(SeqList1* pt)
{
    free(pt->data);
    pt->data=NULL;
}

//头插
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

//头删
void SeqListEraseFront(SeqList1* pt)
{
    pt->data[0]=0;

    memmove(pt->data,pt->data+1,(pt->size-1)*sizeof(SeqListDataType));
    pt->size--;
}

//尾插：
void SeqListPushBack(SeqList1* pt, SeqListDataType x)
{
    if (pt->size == pt->capacity)
    {
	//增加容量：
	CheckCapacity(pt);
    }
    
    pt->data[pt->size]=x;
    pt->size++;

}

//尾部删除
void SeqListEraseBack(SeqList1* pt)
{
    pt->data[pt->size - 1] = 0;
    pt->size--;
}

//在Pos位置插入
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

//在Pos位置删除
void SeqListErasePos(SeqList1* pt, SeqListDataType Pos)
{
    pt->data[Pos-1]=0;
    memmove(pt->data+Pos-1,pt->data+Pos,sizeof(SeqListDataType)*(pt->size-Pos));
    pt->size--;
}
//查找：
int SeqListSearch(SeqList1* pt, SeqListDataType x)
{
   //普通，但是得判断是否越界：
   /*int i=0;
   for (i = 0; i < pt->size; i++)
   {
       if((x)==pt->data[i])
	{
	    return (i+1);
	}
	
	
   }
   return 0;*/

   // 从后往前查找：
   int i=pt->size;
    while(pt->data[i]!=x)
	--i;
    return i+1;

}

//打印
void PrintfSeqList(SeqList1* pt)
{
    int i=0;
    for(i=0;i<pt->size;i++)
    { 
	printf("%d ",pt->data[i]);
    }
    printf("\n");
}

