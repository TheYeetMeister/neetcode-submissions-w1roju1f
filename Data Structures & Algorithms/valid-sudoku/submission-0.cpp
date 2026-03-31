class Solution {
public:
    int calculateMacroGrid(unsigned boardSize, int i, int j) {
        int sizeSquareRoot = sqrt(boardSize);

        return (i / sizeSquareRoot) * sizeSquareRoot + (j / sizeSquareRoot);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowDups(board.size());
        vector<unordered_set<char>> colDups(board.size());
        vector<unordered_set<char>> macroGridDups(board.size());

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                auto it = rowDups[i].find(board[i][j]);
                if (it != rowDups[i].end() && *it != '.') {
                    return false;
                }
                rowDups[i].insert(board[i][j]);

                it = colDups[j].find(board[i][j]);
                if (it != colDups[j].end() && *it != '.') {
                    return false;
                }
                colDups[j].insert(board[i][j]);

                it = macroGridDups[calculateMacroGrid(board.size(), i, j)].find(board[i][j]);
                if (it != macroGridDups[calculateMacroGrid(board.size(), i, j)].end() && *it != '.') {
                    return false;
                }
                macroGridDups[calculateMacroGrid(board.size(), i, j)].insert(board[i][j]);
            }
        }
        return true;
    }
};
