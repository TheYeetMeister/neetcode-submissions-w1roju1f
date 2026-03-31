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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        unsigned res = 0;
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, root->val});

        while (!bfs.empty()) {
            pair<TreeNode*, int> node = bfs.front();
            bfs.pop();

            int currMax = node.second;

            if (node.first->val >= currMax) {
                currMax = node.first->val;
                ++res;
            }

            if (node.first->left) {
                bfs.push({node.first->left, currMax});
            }
            if (node.first->right) {
                bfs.push({node.first->right, currMax});
            }
        }

        return res;
    }
};
