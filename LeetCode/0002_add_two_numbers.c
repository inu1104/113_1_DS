/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int value, carry = 0;
    ListNode *current, *result = (ListNode *)malloc(sizeof(ListNode));
    current = result;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        value = carry;
        if (l1 != NULL)
        {
            value += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            value += l2->val;
            l2 = l2->next;
        }
        carry = value / 10;
        value %= 10;

        ListNode *new = (ListNode *)malloc(sizeof(ListNode));
        new->val = value;
        new->next = NULL;
        current->next = new;
        current = current->next;
    }
    current = result;
    result = result->next;
    free(current);
    return result;
}
