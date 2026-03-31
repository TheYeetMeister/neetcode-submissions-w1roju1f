class Solution {
    int ROWS, COLS;

    bool backtracking(const int i, const int j, int wordPos, 
        vector<vector<char>>& board, string& word) {
        if (wordPos == word.size()) {
            return true;
        }

        if (i == ROWS || i < 0 || 
            j == COLS || j < 0 ||
            board[i][j] == '#' ||
            board[i][j] != word[wordPos]) {
            return false;
        }

        board[i][j] = '#';
        bool ret = backtracking(i + 1, j, wordPos + 1, board, word) ||
                backtracking(i - 1, j, wordPos + 1, board, word) ||
                backtracking(i, j + 1, wordPos + 1, board, word) ||
                backtracking(i, j - 1, wordPos + 1, board, word);
        board[i][j] = word[wordPos];

        return ret;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (backtracking(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
