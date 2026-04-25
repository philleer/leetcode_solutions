/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recursive(TreeNode *root, std::vector<int> &results) {
        if (!root) return ;

        recursive(root->left, results);
        results.push_back(root->val);
        recursive(root->right, results);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {root->val};

        std::vector<int> res;
        recursive(root, res);

        return res;
    }
};