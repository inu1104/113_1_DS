/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

typedef struct ListNode ListNode;

ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    ListNode *result = malloc(sizeof(ListNode));

    ListNode *current = result;
    while (head->next != NULL)
    {
        ListNode *gcd_node = malloc(sizeof(ListNode));
        gcd_node->val = gcd(head->val, head->next->val);
        current->next = head;
        head = head->next;
        current = current->next;
        current->next = gcd_node;
        current = gcd_node;
    }
    current->next = head;
    current = result;
    result = result->next;
    free(current);
    return result;
}
