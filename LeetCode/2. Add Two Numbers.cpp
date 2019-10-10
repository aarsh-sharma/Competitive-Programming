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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = ans;
        int carry = 0, x, y;
        while (p != NULL or q != NULL) {
            if (p == NULL) {
                x = 0;
            } else {
                x = p->val;
                p = p->next;
            }
            if (q == NULL) {
                y = 0;
            } else {
                y = q->val;
                q = q->next;
            }
            int sum = (x + y + carry) % 10;
            carry = (x + y +  carry) / 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return ans->next;
    }
};