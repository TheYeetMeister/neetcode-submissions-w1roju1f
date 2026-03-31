class Solution {
    unordered_set<int> chosenGrids{};
    int calculateGridPos(const int i, const int j, vector<vector<char>>& board) {
        return i * board[0].size() + j;
    }

    bool backtracking(const int i, const int j, int wordPos, 
        vector<vector<char>>& board, string& word) {
        if (wordPos == word.size()) {
            return true;
        }

        int gridPos = calculateGridPos(i, j, board);

        if (i == board.size() || i < 0 || 
            j == board[0].size() || j < 0 ||
            chosenGrids.find(gridPos) != chosenGrids.end() ||
            board[i][j] != word[wordPos]) {
            return false;
        }

        cout << gridPos << endl;
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
