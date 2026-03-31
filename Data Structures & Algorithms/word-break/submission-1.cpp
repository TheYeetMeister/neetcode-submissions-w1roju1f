struct Node {
    bool isWord = false;
    Node* children[26]{nullptr};
};

class Solution {
    Node* root;

    void createTrie(vector<string>& wordDict) {
        root = new Node();

        for (const string& word: wordDict) {
            Node* curr = root;
            for (const char c: word) {
                if (!curr->children[c - 'a']) {
                    curr->children[c - 'a'] = new Node();
                }
                curr = curr->children[c - 'a'];
            }
            curr->isWord = true;
        }
    }

    void destroyTrie(Node* curr) {
        for (int i = 0; i < 26; ++i) {
            if (curr->children[i]) {
                destroyTrie(curr->children[i]);
            }
        }

        delete curr;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        createTrie(wordDict);
        
        vector<bool> wordEnds(s.size() + 1, false);
        wordEnds[0] = true;

        for (int m = 0; m < s.size() + 1; ++m) {
            if (wordEnds[m]) {
                Node* curr = root;
                for (int i = m; i < s.size() && curr->children[s[i] - 'a']; ++i) {
                    if (curr->children[s[i] - 'a']->isWord) {
                        wordEnds[i + 1] = true;
                    }
                    curr = curr->children[s[i] - 'a'];
                }
            }
        }

        destroyTrie(root);

        return wordEnds.back();
    }
};
