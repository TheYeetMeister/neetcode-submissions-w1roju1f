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
    int res;

    int dfs(TreeNode* curr) {
        if (!curr) {
            return 0;
        } 

        int left = max(dfs(curr->left), 0);
        int right = max(dfs(curr->right), 0);

        int retValue = curr->val + max(left, right);

        res = max(curr->val + left + right, res);

        return retValue;
    }
public:
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        
        dfs(root);

        return res;
    }
};
