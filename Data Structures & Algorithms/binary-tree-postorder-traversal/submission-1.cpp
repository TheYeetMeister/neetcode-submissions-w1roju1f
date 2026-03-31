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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> res;
        stack<TreeNode*> traverse;
        unordered_set<TreeNode*> checked;
        traverse.push(root);

        while (!traverse.empty()) {
            TreeNode* curr = traverse.top();

            if (curr->left && checked.find(curr->left) == checked.end()) {
                traverse.push(curr->left);
                continue;
            }

            if (curr->right && checked.find(curr->right) == checked.end()) {
                traverse.push(curr->right);
                continue;
            }

            checked.insert(curr);
            res.push_back(curr->val);
            traverse.pop();
        }

        return res;
    }
};