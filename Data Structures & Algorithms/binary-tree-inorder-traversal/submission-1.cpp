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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<int> res;

        stack<TreeNode*> checkLeft;
        stack<TreeNode*> checkRight;
        checkLeft.push(root);

        while (!checkLeft.empty() || !checkRight.empty()) {
            while (!checkLeft.empty()) {
                TreeNode* curr = checkLeft.top();
                checkLeft.pop();

                if (curr->left) {
                    checkLeft.push(curr->left);
                }

                checkRight.push(curr);
            }

            if (!checkRight.empty()) {
                TreeNode* curr = checkRight.top();
                checkRight.pop();

                res.push_back(curr->val);
                
                if (curr->right) {
                    checkLeft.push(curr->right);
                }
            }
        }

        return res;
    }
};