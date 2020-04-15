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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ansNode = new ListNode(0);
        ListNode *head = ansNode;
        int flag = 0, k = lists.size();
        while (true) {
            int idx = -1;
            for (int i = 0; i < k; i++) {
                if (lists[i] == NULL) continue;
                if (idx == -1 or (lists[i]->val < lists[idx]->val)) {
                    idx = i;
                }
            }
            if (idx == -1) break;
            ansNode->next = lists[idx];
            lists[idx] = lists[idx]->next;
            ansNode = ansNode->next;
        }
        return head->next;
    }
};