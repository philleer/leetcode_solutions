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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode *cur_node = head;
        ListNode *tail = nullptr;
        int len = 0;
        while (cur_node) {
            ++len;
            if (!cur_node->next) tail = cur_node;
            cur_node = cur_node->next;
        }

        k = k % len;

        int node_index = len - k;
        int cnt = 0;
        cur_node = head;
        while (cur_node) {
            if (++cnt == node_index) {
                tail->next = head;
                head = cur_node->next;
                cur_node->next = nullptr;
                break;
            }
            cur_node = cur_node->next;
        }

        return head;
    }
};