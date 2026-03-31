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
    void dfs(TreeNode* curr, vector<int>& buf) {
        if (curr == nullptr) {
            return;
        }

        dfs(curr->left, buf);
        buf.push_back(curr->val);
        dfs(curr->right, buf);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        dfs(root, res);

        return res;
    }
};