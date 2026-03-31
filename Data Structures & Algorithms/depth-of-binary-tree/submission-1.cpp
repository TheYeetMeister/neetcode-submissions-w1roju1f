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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int res = 1;

        queue<pair<int, TreeNode*>> bfsTree;
        bfsTree.push(make_pair(res, root));

        while (!bfsTree.empty()) {
            pair<int, TreeNode*> currNode = bfsTree.front();
            bfsTree.pop();

            res = max(res, currNode.first);

            if (currNode.second->left) {
                bfsTree.push(make_pair(currNode.first + 1, currNode.second->left));
            }

            if (currNode.second->right) {
                bfsTree.push(make_pair(currNode.first + 1, currNode.second->right));
            }
        }

        return res;
    }
};
