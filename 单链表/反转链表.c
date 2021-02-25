struct SListNode {
	SListNode data;
	SListNode* next;
};


struct SListNode* reverseList(struct SListNode* head) {
	struct SListNode* prve=NULL;
	struct SListNode* cur=head;
	struct SListNode* NEXT=head->next;
	struct SListNode* newNode=NULL;

	//Í·²å
	/*while (cur != NULL)
	{
		struct SListNode* Next=cur->next;
		if()
		cur->next=newNode;

		cur=Next;
		
	}

	return newNode;
	*/

	//µü´ú£º
	while (cur)
	{
		cur->next=prve;

		prve=cur;
		cur=NEXT
		if(NEXT)
			NEXT=NEXT->next;
	}
	return prve;
}