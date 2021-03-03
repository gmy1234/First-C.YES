
  
  struct ListNode {
      int val;
      struct ListNode *next;
  };

typedef struct ListNode ListNode;

//反转链表：
struct ListNode* reverseList(struct ListNode* head)
{
    ListNode* newList = NULL;
    ListNode* cur = head;

    while (cur)
    {
        ListNode* Next = cur->next;

        cur->next = newList;
        newList = cur;

        cur = Next;
    }

    return newList;

}

bool isPalindrome(struct ListNode* head) {

    //找中间数：
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* cur = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

    }

    slow = reverseList(slow);
    ListNode* Last = slow;

    while (slow != NULL)
    {
        if (slow->val == cur->val)
        {
            slow = slow->next;
            cur = cur->next;
        }
        else
            return false;
    }
    return true;

}