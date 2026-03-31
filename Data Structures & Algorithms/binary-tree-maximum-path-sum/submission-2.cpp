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
    int res = INT_MIN;

    int maxPathHelper(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = maxPathHelper(root->left);
        int right = maxPathHelper(root->right);

        res = max(res, root->val + left + right);

        int maxPath = max(root->val + left, root->val + right);

        maxPath = max(maxPath, root->val);

        return max(maxPath, 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPathHelper(root);

        return res;
    }
};
