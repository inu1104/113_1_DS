/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *result = malloc(sizeof(ListNode));
    ListNode *current = result;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    if (l1 != NULL)
        current->next = l1;
    if (l2 != NULL)
        current->next = l2;

    current->next = l1 ? l1 : l2;
    current = result;
    result = result->next;
    free(current);
    return result;
}

ListNode *merge(ListNode **Lists, int head, int rear){
    if(head == rear)
        return Lists[head];

    int middle = (head + rear) / 2;
    Lists[head] = merge(Lists, head, middle);
    Lists[middle + 1] = merge(Lists, middle + 1, rear);
    Lists[head] = mergeTwoLists(Lists[head], Lists[middle + 1]);

    return Lists[head];
}

ListNode *mergeKLists(ListNode **lists, int listsSize)
{ 
    if(listsSize == 0)
        return NULL;
    ListNode *result = merge(lists, 0, listsSize - 1);    
    return result;
}
