
 
struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    //½»µã
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    if (headB == NULL || headA == NULL)
        return NULL;

    while (curA != curB)
    {
        //curA = curA != NULL ? curA->next : headB;

        if (curA == NULL)
            curA = headB;
        else
            curA = curA->next;


        //curB = curB != NULL ? curB->next : headA;
        if (curB == NULL)
            curB = headA;
        else
        {
            curB = curB->next;
        }

    }
    return curA;


}