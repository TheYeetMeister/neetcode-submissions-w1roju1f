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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (!root) {
            return res;
        }

        queue<TreeNode*> oldBfs;
        queue<TreeNode*> newBfs;
        oldBfs.push(root);

        while (!oldBfs.empty()) {
            res.push_back(vector<int>{});
            while(!oldBfs.empty()) {
                TreeNode* node = oldBfs.front();
                oldBfs.pop();

                res[res.size() - 1].push_back(node->val);
                if (node->left) {
                    newBfs.push(node->left);
                }
                if (node->right) {
                    newBfs.push(node->right);
                }
            }
            swap(oldBfs, newBfs);
        }

        return res;
    }
};
