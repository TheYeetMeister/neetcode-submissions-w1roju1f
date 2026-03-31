class Solution {
    void incQueenSquares(int i, int j, vector<vector<int>>& queenSight, const bool add) {
        //flip columns
        for (int k = i + 1; k < queenSight.size(); ++k) {
            (add) ? ++queenSight[k][j]: --queenSight[k][j];
        }

        for (int k = i + 1, m = j + 1; k < queenSight.size() && m <queenSight[0].size(); ++k, ++m) {
            (add) ? ++queenSight[k][m]: --queenSight[k][m];
        }

        for (int k = i + 1, m = j - 1; k < queenSight.size() && m >= 0; ++k, --m) {
            (add) ? ++queenSight[k][m]: --queenSight[k][m];
        }
    }

    void backtracking(int i, vector<string>& currBoard, 
        vector<vector<int>>& queenSight, vector<vector<string>>& res) {
        if (i >= queenSight.size()) {
            res.push_back(currBoard);
            return;
        }

        string currStr = string(queenSight.size(), '.');

        for (int j = 0; j < queenSight.size(); ++j) {
            if (!queenSight[i][j]) {
                incQueenSquares(i, j, queenSight, true);
                currStr[j] = 'Q';

                currBoard.push_back(currStr);
                backtracking(i + 1, currBoard, queenSight, res);
                currBoard.pop_back();

                currStr[j] = '.';
                incQueenSquares(i, j, queenSight, false);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> queenSight(n, vector<int>(n, 0));
        vector<vector<string>> res{};
        vector<string> currBoard{};
        currBoard.reserve(n);

        backtracking(0, currBoard, queenSight, res);

        return res;
    }
};
