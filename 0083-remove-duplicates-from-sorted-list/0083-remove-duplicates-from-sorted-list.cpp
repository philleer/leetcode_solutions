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
        ListNode *next = head->next;
        int last_val = node->val;
        while (next) {
            if (node->val == next->val) {
                node->next = next->next;
                next = next->next;
            } else {
                node = node->next;
                next = next->next;
            }
        }

        return head;
    }
};