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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        queue<TreeNode*> nodesToInvert;
        nodesToInvert.push(root);

        while (!nodesToInvert.empty()) {
            TreeNode* currentNode = nodesToInvert.front();
            nodesToInvert.pop();

            TreeNode* tmp = currentNode->left;
            currentNode->left = currentNode->right;
            currentNode->right = tmp;

            if (currentNode->left) {
                nodesToInvert.push(currentNode->left);
            }

            if (currentNode->right) {
                nodesToInvert.push(currentNode->right);
            }
        }

        return root;
    }
};
