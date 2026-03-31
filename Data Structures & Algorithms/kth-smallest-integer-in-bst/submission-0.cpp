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
    //the int returns the number of values passed
    int res = -1;

    int chosenValue(TreeNode* root, int k, int topIndex) {
        if (!root) {
            return topIndex;
        }

        int currIndex = 1 + chosenValue(root->left, k, topIndex);

        if (currIndex == k) {
            res = root->val;
            return currIndex + 1;
        } else if (k < currIndex) {
            return currIndex;
        } else {
            return chosenValue(root->right, k, currIndex);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        while (root && index < k) {
            index = chosenValue(root, k, index);
            root = root->right;
        }
        return res;
    }
};
