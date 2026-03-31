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
        if (curr) {
            dfs(curr->left, buf);
            dfs(curr->right, buf);
            buf.push_back(curr->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        dfs(root, res);

        return res;
    }
};