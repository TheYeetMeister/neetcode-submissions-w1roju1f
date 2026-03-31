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
    TreeNode* searchBST(TreeNode* curr, int key, TreeNode* &prev) {
        while (curr && curr->val != key) {
            prev = curr;

            if (curr->val > key) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return curr;
    }

    TreeNode* findLargestPossibleNode(TreeNode* curr, TreeNode* &prev) {
        while (curr->right) {
            prev = curr;
            curr = curr->right;
        }

        return curr;
    }

    TreeNode* findSmallestPossibleNode(TreeNode* curr, TreeNode* &prev) {
        while (curr->left) {
            prev = curr;
            curr = curr->left;
        }

        return curr;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* prev = nullptr;
        TreeNode* rm = searchBST(root, key, prev);

        if (rm == nullptr) {
            return root;
        }

        TreeNode* leaf = nullptr;
        if (rm->left) {
            prev = rm;
            leaf = findLargestPossibleNode(rm->left, prev);
        } else if (rm->right) {
            prev = rm;
            leaf = findSmallestPossibleNode(rm->right, prev);
        }

        if (leaf) {
            swap(leaf->val, rm->val);
            rm = leaf;
        }

        if (!prev) {
            delete rm;
            return nullptr;
        }

        TreeNode* attachBranch = (rm->right)? rm->right: rm->left;
        if (prev->right == rm) {
            prev->right = attachBranch;
        } else {
            prev->left = attachBranch;
        }

        delete rm;
        return root;
    }
};