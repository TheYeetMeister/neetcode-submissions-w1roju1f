struct TrieNode {
    int numOfPaths = 0;
    TrieNode* children[26]{nullptr};
    string word = "";
};

class Solution {
    TrieNode* root;
    vector<string> res;
    int row;
    int col;

    void createTrieTree(vector<string>& words) {
        root = new TrieNode();

        for (string word: words) {
            TrieNode* curr = root;
            for (char c: word) {
                if (!curr->children[c - 'a']) {
                    curr->children[c - 'a'] = new TrieNode();
                }

                curr = curr->children[c - 'a'];
                ++curr->numOfPaths;    
            }
            curr->word = word;
        }
    }

    bool dfsBacktrackWord(int i, int j,
        vector<vector<char>>& board, TrieNode* currNode) {
            if (i < 0 || i >= row ||
                j < 0 || j >= col ||
                board[i][j] == '#' ||
                !currNode->children[board[i][j] - 'a'] ||
                !currNode->children[board[i][j] - 'a']->numOfPaths) {
                    return false;
            }

            currNode = currNode->children[board[i][j] - 'a'];
            --currNode->numOfPaths;
            if (currNode->word != "") {
                res.push_back(currNode->word);
                currNode->word = "";
                return true;
            }

            char currChar = board[i][j];
            board[i][j] = '#';

            bool value = dfsBacktrackWord(i + 1, j, board, currNode) ||
                dfsBacktrackWord(i - 1, j, board, currNode) ||
                dfsBacktrackWord(i, j + 1, board, currNode) ||
                dfsBacktrackWord(i, j - 1, board, currNode);

            board[i][j] = currChar;

            if (value) {
                return true;
            } else {
                ++currNode->numOfPaths;
                return false;
            }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        col = board[0].size();
        res = vector<string>{};
        createTrieTree(words);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                while (dfsBacktrackWord(i, j, board, root));
            }
        }

        return res;
    }
};
