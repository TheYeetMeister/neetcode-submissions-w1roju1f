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
    int nodeTraversal(TreeNode* root, int prev) {
        if (!root) {
            return 0;
        }

        if (root->val >= prev) {
            int left = nodeTraversal(root->left, root->val);
            int right = nodeTraversal(root->right, root->val);
            return 1 + right + left;
        } else {
            int left = nodeTraversal(root->left, prev);
            int right = nodeTraversal(root->right, prev);
            return right + left;
        }
    }
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + nodeTraversal(root->left, root->val) + nodeTraversal(root->right, root->val);
    }
};
