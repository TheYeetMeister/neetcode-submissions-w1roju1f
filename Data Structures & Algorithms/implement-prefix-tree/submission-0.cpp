struct TreeNode{
    bool isWord = false;
    TreeNode* children[26] {nullptr};
};

class PrefixTree {
    TreeNode* root;
    void deleteTreeNode(TreeNode* node) {
        for (TreeNode* child: node->children) {
            if (child) {
                deleteTreeNode(child);
            }
        }

        delete node;
    }

    TreeNode* searchWord(string word) {
        TreeNode* currNode = root;

        for (char c: word) {
            if (!currNode->children[c - 'a']) {
                return nullptr;
            }
            currNode = currNode->children[c - 'a'];
        }

        return currNode;
    }

public:
    PrefixTree(): root(new TreeNode()) {}

    ~PrefixTree() {
        deleteTreeNode(root);
    }

    
    void insert(string word) {
        int i = 0;
        TreeNode* currNode = root;

        for (; i < word.size(); ++i) {
            if (!currNode->children[word[i] - 'a']) {
                currNode->children[word[i] - 'a'] = new TreeNode();
            }
            currNode = currNode->children[word[i] - 'a'];
        }

        if (!currNode->isWord) {
            currNode->isWord = true;
        }
    }
    
    bool search(string word) {
        TreeNode* output = searchWord(word);

        return output && output->isWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* output = searchWord(prefix);

        return output;
    }
};
