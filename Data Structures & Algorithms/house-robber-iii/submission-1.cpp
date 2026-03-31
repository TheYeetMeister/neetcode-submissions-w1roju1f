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
    unordered_map<TreeNode*, int> maxSkip;
    unordered_map<TreeNode*, int> maxTake;
    
    int dfsSkip(TreeNode* curr) {
        if (maxSkip.find(curr) != maxSkip.end()) {
            return maxSkip[curr];
        }
        
        return maxSkip[curr] = dfs(curr->left) + dfs(curr->right);
    }
    int dfs(TreeNode* curr) {
        if (maxTake.find(curr) != maxTake.end()) {
            return maxTake[curr];
        }

        return maxTake[curr] = max(curr->val + dfsSkip(curr->left) + dfsSkip(curr->right), 
            dfs(curr->left) + dfs(curr->right));
    }
public:
    int rob(TreeNode* root) {
        maxTake[nullptr] = 0;
        maxSkip[nullptr] = 0;

        return dfs(root);
    }
};