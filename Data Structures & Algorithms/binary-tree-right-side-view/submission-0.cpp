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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res{};

        if (!root) return res;

        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int end = bfs.size() - 1;

            TreeNode* node = bfs.front();
            for (int i = 0; i < end; ++i) {
                if (node->left) {
                    bfs.push(node->left);
                }
                if (node->right) {
                    bfs.push(node->right);
                }
                bfs.pop();
                node = bfs.front();
            }

            if (node->left) {
                bfs.push(node->left);
            }
            if (node->right) {
                bfs.push(node->right);
            }
            res.push_back(bfs.front()->val);
            bfs.pop();
        }

        return res;
    }
};
