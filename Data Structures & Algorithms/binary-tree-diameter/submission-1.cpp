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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> dfs;
        dfs[nullptr] = {0, 0};
        stack<TreeNode*> stack;
        stack.push(root);

        while(!stack.empty()) {
            TreeNode* node = stack.top();

            if (node->left && dfs.find(node->left) == dfs.end()) {
                stack.push(node->left);
            } else if (node->right && dfs.find(node->right) == dfs.end()) {
                stack.push(node->right);
            } else {
                stack.pop();

                pair<int, int> left = dfs[node->left];
                int leftHeight = left.first;
                int leftDiameter = left.second;

                pair<int, int> right = dfs[node->right];
                int rightHeight = right.first;
                int rightDiameter = right.second;

                int height = 1 + max(leftHeight, rightHeight);
                int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

                dfs[node] = {height, diameter};
            }
        }

        return dfs[root].second;
    }
};
