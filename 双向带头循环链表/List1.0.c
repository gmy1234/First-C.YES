
typedef  int ListDataType;
typedef struct ListNode {
	ListNode* prve;
	ListNode* next;
	ListDataType x;
}ListNode;


LTnode* BuyLTnode(ListDataType x)
{
	LTnode* newNode = (LTnode*)malloc(sizeof(LTnode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->next = NULL;
	newNode->prve = NULL;
	newNode->data = x;
	return newNode;

}


void ListPushBack(LTnode** pphead, ListDataType x)
{

	assert(*pphead != NULL);
	LTnode* tail = (*pphead)->prve;		//tail±£´æÎ²Ö¸Õë

	LTnode* newNode = BuyLTnode(x);

	tail->next = newNode;					// 1.
	newNode->prve = tail->next;			//2.
	(*pphead)->prve = newNode;			//3.
	newNode->next = *pphead;				//4.

}

void ListInit(LTnode** pphead)
{
	*pphead = BuyLTnode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prve = *pphead;


}

void ListPrint(LTnode* phead)
{
	LTnode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}


}