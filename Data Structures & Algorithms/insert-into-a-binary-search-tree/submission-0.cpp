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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr) {
            prev = curr;

            if (curr->val > val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        TreeNode* returnNode = new TreeNode(val);

        if (prev) {
            if (prev->val > val) {
                prev->left = returnNode;
            } else {
                prev->right = returnNode;
            }
        }

        return (root)? root: returnNode;
    }
};