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
    TreeNode* findLeftMostVal(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        while (root->left) {
            root = root->left;
        }

        return root;
    }

    TreeNode* findRightMostVal(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        while (root->right) {
            root = root->right;
        }

        return root;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* leftNode = findLeftMostVal(root);
        TreeNode* rightNode = findRightMostVal(root);

        while (true) {
            TreeNode* newLeft = findLeftMostVal(root->right);
            TreeNode* newRight = findRightMostVal(root->left);

            if (newLeft && 
                newLeft->val <= p->val && 
                newLeft->val <= q->val) {
                    root = root->right;
            } else if (newRight &&
                        newRight->val >= p->val &&
                        newRight->val >= q->val) {
                            root = root->left;
            } else {
                return root;
            }
        }
    }
};
