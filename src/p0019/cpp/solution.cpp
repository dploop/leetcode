/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0 || !head)  return head;
        ListNode *prev, *curr, *temp=head;
        for (; temp&&(--n); temp=temp->next);
        if (!temp) return head;
        for (curr=head; temp=temp->next; ) {
            prev = curr; curr = curr->next;
        }
        if (head == curr) {
            head = head->next;
        } else {
            prev->next = curr->next;
        }
        return head;
    }
};
