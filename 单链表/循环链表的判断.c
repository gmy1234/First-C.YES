
 
 struct ListNode {
     int val;
      struct ListNode *next;
  }
 
bool hasCycle(struct ListNode* head) {

    if (head == NULL)
    {
        return false;
    }


    //¿ìÂıÖ¸Õë
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
} 