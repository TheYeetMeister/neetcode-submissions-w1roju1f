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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
                            int preorderBegin, int preorderEnd,
                            int inorderBegin, int inorderEnd,
                            unordered_map<int, int>& valueToIndex) {
        if (preorderBegin > preorderEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preorderBegin]);

        int splitPoint = valueToIndex[preorder[preorderBegin]];

        int size = splitPoint - inorderBegin;


        TreeNode* left = buildTreeHelper(preorder, inorder, 
                                    preorderBegin + 1, preorderBegin + size, 
                                    inorderBegin, inorderBegin + size - 1,
                                    valueToIndex);

        TreeNode* right = buildTreeHelper(preorder, inorder, 
                                            preorderBegin + size + 1, preorderEnd, 
                                            inorderBegin + size + 1, inorderEnd,
                                            valueToIndex);
        
        root->left = left;
        root->right = right;

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> valueToIndex{};

        for (int i = 0; i < inorder.size(); ++i) {
            valueToIndex[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, inorder, 
                            0, preorder.size() - 1, 
                            0, inorder.size() - 1,
                            valueToIndex);
    }
};
