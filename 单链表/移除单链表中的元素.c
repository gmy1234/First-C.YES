
 struct SListNode {
	SListNode val;
	SListNode* next;
};

 struct SListNode* removeElements(struct SListNode* head, int val) {
	
	 struct SListNode* prve=NULL;
	 struct SListNode* cur=head;
	while(cur)
	{
		if (cur->next = val)
		{
			if (cur == head)
			{
				//Í·É¾£º
				head=cur->next;
				free(cur);
				cur=head;
				
			}
			else
			{ 
			prve->next=cur->next;
			free(cur);
			}
		}
		else
		{
			prve=cur;
			cur=cur->next;
		}
	}
	return head;

 }