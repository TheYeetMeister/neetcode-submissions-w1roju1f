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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<int> res;
        stack<TreeNode*> buf;
        buf.push(root);

        while (!buf.empty()) {
            TreeNode* curr = buf.top();
            buf.pop();

            res.push_back(curr->val);

            if (curr->right) {
                buf.push(curr->right);
            }

            if (curr->left) {
                buf.push(curr->left);
            }
        }

        return res;
    }
};