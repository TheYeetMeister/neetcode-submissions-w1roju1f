#define NUM_CHARS 26

struct TrieNode {
    bool isWord = false;
    TrieNode* children[NUM_CHARS]{nullptr};
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary(): root{new TrieNode()} {}
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c: word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }

        if (!curr->isWord) {
            curr->isWord = true;
        }
    }
    
    bool search(string word) {
        queue<TrieNode*> frontier;
        frontier.push(root);
        
        for (char c: word) {
            if (frontier.empty()) {
                return false;
            }

            int size = frontier.size();

            for (int i = 0; i < size; ++i) {
                TrieNode* curr = frontier.front();
                frontier.pop();

                if (c != '.') {
                    if (curr->children[c - 'a']) {
                        frontier.push(curr->children[c - 'a']);
                    }

                    continue;
                }

                for (int j = 0; j < NUM_CHARS; ++j) {
                    if (curr->children[j]) {
                        frontier.push(curr->children[j]);
                    }
                } 
            }

        }
        while(!frontier.empty()) {
            TrieNode* curr = frontier.front();
            frontier.pop();

            if (curr->isWord) {
                return true;
            }
        }

        return false;
    }
};
