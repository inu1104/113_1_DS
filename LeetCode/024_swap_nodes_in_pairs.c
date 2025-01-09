/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *current, *next, *prev;
    current = head;
    while(current!= NULL && current->next!= NULL){
        next = current->next;

        current->next = next->next;
        next->next = current;
        //swap current and next

        if(current == head)
            head = next;
        else
            prev->next = next;
        prev = current;
        current = current->next;
    }
    return head;
}
