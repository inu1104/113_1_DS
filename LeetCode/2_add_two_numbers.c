/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;

node *addTwoNumbers(node *l1, node *l2)
{
    int value, carry = 0;
    node *current, *result = (node *)malloc(sizeof(node));
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

        node *new = (node *)malloc(sizeof(node));
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
