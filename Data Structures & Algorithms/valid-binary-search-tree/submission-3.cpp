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
    pair<bool, pair<int, int>> checkNodeValiditiy(TreeNode* node) {

        int leftMin = node->val;
        int leftMax = INT_MIN;
        if (node->left) {
            pair<bool, pair<int, int>> leftInfo = checkNodeValiditiy(node->left);
            if (!leftInfo.first) return {false, {0, 0}};

            leftMin = leftInfo.second.first;
            leftMax = leftInfo.second.second;
        }

        int rightMin = INT_MAX;
        int rightMax = node->val;
        if (node->right) {
            pair<bool, pair<int, int>> rightInfo = checkNodeValiditiy(node->right);
            if (!rightInfo.first) return {false, {0, 0}};

            rightMin = rightInfo.second.first;
            rightMax = rightInfo.second.second;
        }
        
        if (leftMax >= node->val || rightMin <= node->val) {
            return {false, {0, 0}};
        } else {
            return {true, {leftMin, rightMax}};
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        return checkNodeValiditiy(root).first;
    }
};
