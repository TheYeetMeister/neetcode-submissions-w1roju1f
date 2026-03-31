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
    TreeNode* dfs(TreeNode* curr, int target) {
        if (curr == nullptr) {
            return nullptr;
        }

        curr->right = dfs(curr->right, target);
        curr->left = dfs(curr->left, target);

        if (curr->val == target && curr->right == nullptr && curr->left == nullptr) {
            delete curr;
            return nullptr;
        } else {
            return curr;
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};