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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next || left >= right) return head;

        ListNode *left_node = nullptr;
        ListNode *right_node = nullptr;
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *cur = dummy_head;
        int len = 0;
        while (cur) {
            ++len;
            if (len == left) {
                left_node = cur;
            }
            if (len - 1 == right) {
                right_node = cur;
            }
            cur = cur->next;
        }

        // reverse linked list
        ListNode *dummy_pre = new ListNode(-100);
        ListNode *pre = dummy_pre;
        ListNode *next = nullptr;
        cur = left_node->next;
        while (cur != right_node) {
            next = cur->next;
            if (cur == left_node->next) {
                cur->next = right_node->next;
            } else {
                cur->next = pre;
            }
            pre = cur;
            cur = next;
        }
        cur->next = pre;
        left_node->next = cur;

        if (left_node == dummy_head) {
            dummy_head->next = right_node;
        } else {
            dummy_head->next = head;
        }

        return dummy_head->next;
    }
};