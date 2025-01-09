/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

node *mergeTwoLists(node *l1, node *l2)
{
    node *result = malloc(sizeof(node));
    node *current = result;
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

    current->next = l1 ? l1 : l2;
    current = result;
    result = result->next;
    free(current);
    return result;
}
