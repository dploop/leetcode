class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int result = 0;
        while (head) {
            result = result * 2 + head->val;
            head = head->next;
        }
        return result;
    }
};
