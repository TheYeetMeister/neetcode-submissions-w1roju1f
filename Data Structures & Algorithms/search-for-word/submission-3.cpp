class Solution {
    int ROWS, COLS;

    unordered_set<int> chosenGrids{};
    int calculateGridPos(const int i, const int j, vector<vector<char>>& board) {
        return i * COLS + j;
    }

    bool backtracking(const int i, const int j, int wordPos, 
        vector<vector<char>>& board, string& word) {
        if (wordPos == word.size()) {
            return true;
        }

        int gridPos = calculateGridPos(i, j, board);

        if (i == ROWS || i < 0 || 
            j == COLS || j < 0 ||
            chosenGrids.find(gridPos) != chosenGrids.end() ||
            board[i][j] != word[wordPos]) {
            return false;
        }

        chosenGrids.insert(gridPos);
        ++wordPos;
        bool ret = backtracking(i + 1, j, wordPos, board, word) ||
                backtracking(i - 1, j, wordPos, board, word) ||
                backtracking(i, j + 1, wordPos, board, word) ||
                backtracking(i, j - 1, wordPos, board, word);

        chosenGrids.erase(gridPos);

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
