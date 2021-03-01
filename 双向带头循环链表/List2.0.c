//ͷ��
void ListPushFront(LTnode** pphead, ListDataType x)
{
	assert(*pphead);

	LTnode* first = (*pphead)->next;
	LTnode* newNode = BuyLTnode(x);

	(*pphead)->next = newNode;
	newNode->prve = *pphead;

	newNode->next = first;
	first->prve = newNode;

}

//ͷɾ
void ListPopFront(LTnode* phead)
{
	assert(phead);
	LTnode* First = phead->next;
	LTnode* second = First->next;

	phead->next = second;
	second->prve = phead;
	free(First);

}

//����
LTnode* ListFind(LTnode* phead, ListDataType x)
{
	assert(phead);
	LTnode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;

	}
	return NULL;
}

//pos�����
void ListPosInsert(LTnode** pphead, ListDataType x)
{
	assert(*pphead);

	LTnode* pos = ListFind(*pphead, 3);

	LTnode* posNext = pos->next;
	LTnode* newNode = BuyLTnode(x);

	pos->next = newNode;
	newNode->prve = pos;
	newNode->next = posNext;
	posNext->prve = newNode;

}
