//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode* next;
    };

 // �ݹ�ķ�����
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    //l1����l2Ϊ��
    if (l2 == NULL)
        return l1;
    if (l1 == NULL)
        return l2;

    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

}

//������
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    //l1����l2Ϊ��
    if (l2 == NULL)
        return l1;
    if (l1 == NULL)
        return l2;

    Node* head=NULL;
    Node* tail=NULL;

    if (l1->val < l2->val)
    {
        head=tail=l1;
        l1=l1->next;
    }
    else
    {
        head = tail = l2;
        l2=l2->next;
    }
    
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next=l1;
            l1=l1->next;
        }
        else
        {
            tail->next=l2;
            l2=l2->next;

        }
        tail=tail->next;
    }
    if(l1)
        tail->next =l1;
    else
        tail->next =l2;
    
    return head;  
}