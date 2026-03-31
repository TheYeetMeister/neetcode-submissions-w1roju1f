class Solution {
    int directions[4][2]{
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };

    int ROW, COL;

    bool isLowest(vector<vector<int>>& matrix, int i, int j) {
        for (int k = 0; k < 4; ++k) {
            int row = i + directions[k][0];
            int col = j + directions[k][1];

            if (row == ROW || row < 0 ||
                col == COL || col < 0) {
                continue;
            }

            if (matrix[row][col] < matrix[i][j]) {
                return false;
            }
        }

        return true;
    }

    int longestSequence(vector<vector<int>>& matrix, int i, int j, int prev) {
        if (i == ROW || i < 0 || j == COL || j < 0 || matrix[i][j] <= prev) {
            return 0;
        }

        int res = 1;
        for (int k = 0; k < 4; ++k) {
            int row = i + directions[k][0];
            int col = j + directions[k][1];

            res = max(res, 1 + longestSequence(matrix, row, col, matrix[i][j]));
        }

        return res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 1;
        ROW = matrix.size();
        COL = matrix[0].size();

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (isLowest(matrix, i, j)) {
                    res = max(longestSequence(matrix, i, j, -1), res);
                }
            }
        }

        return res;
    }
};
