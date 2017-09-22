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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2; if (!l2) return l1;
        if (l1->val > l2->val) swap(l1, l2);
        ListNode *p1 = l1, *p2 = l2, *tmp;
        for (; p1->next && p2; ) {
            if (p1->next->val <= p2->val) {
                p1 = p1->next; continue;
            }
            tmp = p2;  p2 = p2->next;
            tmp->next = p1->next;
            p1->next = tmp; p1 = tmp;
        }
        if (p2) {p1->next = p2;}
        return l1;
    }
};
