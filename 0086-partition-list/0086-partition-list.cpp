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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *cur = head;
        ListNode *new_head = new ListNode(-1);
        ListNode *pre = new_head;
        ListNode *dummy = new ListNode(-1);
        ListNode *sub = dummy;
        while (cur) {
            if (cur->val < x) {
                pre->next = cur;
                pre = pre->next;
            } else {
                sub->next = cur;
                sub = sub->next;
            }
            cur = cur->next;
        }
        sub->next = nullptr;
        pre->next = dummy->next;

        return new_head->next;
    }
};