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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        int splitPoint = 0;

        for (; inorder[splitPoint] != root->val; ++splitPoint);


        vector<int> leftPreOrder{preorder.begin() + 1, preorder.begin() + splitPoint + 1};
        vector<int> leftInOrder{inorder.begin(), inorder.begin() + splitPoint};
        TreeNode* left = buildTree(leftPreOrder, leftInOrder);

        vector<int> rightPreOrder{preorder.begin() + splitPoint + 1, preorder.end()};
        vector<int> rightInOrder{inorder.begin() + splitPoint + 1, inorder.end()};
        TreeNode* right = buildTree(rightPreOrder, rightInOrder);
        
        root->left = left;
        root->right = right;

        return root;
    }
};
