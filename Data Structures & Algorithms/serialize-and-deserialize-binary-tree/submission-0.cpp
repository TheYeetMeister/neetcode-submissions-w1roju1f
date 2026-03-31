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

class Codec {
    char delimiter = '@';
    string getValue(string& data, int& currentPoint) {
        string value = "";

        for (; data[currentPoint] != delimiter; ++currentPoint) {
            value.push_back(data[currentPoint]);
        } 

        ++currentPoint;
        return value;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        string res = "";
        res += to_string(root->val) + delimiter;

        queue<TreeNode*> seralizeChildren;
        seralizeChildren.push(root);

        while (!seralizeChildren.empty()) {
            TreeNode* node = seralizeChildren.front();
            seralizeChildren.pop();

            if (node->left) {
                res += to_string(node->left->val);
                seralizeChildren.push(node->left);
            }
            res += delimiter;

            if (node->right) {
                res += to_string(node->right->val);
                seralizeChildren.push(node->right);
            }
            res += delimiter;
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        int pos = 0;
        string value = getValue(data, pos);

        TreeNode* root = new TreeNode(stoi(value));
        queue<TreeNode*> makeChildren;
        makeChildren.push(root);

        while (pos < data.size()) {
            TreeNode* curr = makeChildren.front();
            makeChildren.pop();

            TreeNode* child = nullptr;
            value = getValue(data, pos);
            if (!value.empty()) {
                child = new TreeNode(stoi(value));
                makeChildren.push(child);
            }
            curr->left = child;

            child = nullptr;
            value = getValue(data, pos);
            if (!value.empty()) {
                child = new TreeNode(stoi(value));
                makeChildren.push(child);
            }
            curr->right = child;
        }

        return root;
    }
};
