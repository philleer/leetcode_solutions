/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *node = head;
        ListNode *dummy = new ListNode(-101);
        ListNode *pre = dummy;
        int last_val = pre->val;
        while (node) {
            if (node->next && node->val == node->next->val) {
                last_val = node->val;
                node = node->next;
                pre->next = node;
            } else {
                if (last_val == node->val) {
                    node = node->next;
                    pre->next = node;
                } else {
                    last_val = node->val;
                    pre->next = node;
                    node = node->next;
                    pre = pre->next;
                }
            }
        }

        return dummy->next;
    }
};