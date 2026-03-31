class Solution {
    int directions[4][2]{
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };

    int ROW, COL;

    vector<vector<int>> count;

    bool isLowest(vector<vector<int>>& matrix, int i, int j) {
        if (count[i][j] > 1) {
            return false;
        }

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

    void longestSequence(vector<vector<int>>& matrix, int i, int j, int prev, int cnt) {
        if (i == ROW || i < 0 || j == COL 
            || j < 0 || matrix[i][j] <= prev ||
            count[i][j] > cnt) {
            return;
        }

        count[i][j] = cnt;
        for (int k = 0; k < 4; ++k) {
            int row = i + directions[k][0];
            int col = j + directions[k][1];

            longestSequence(matrix, row, col, matrix[i][j], cnt + 1);
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 1;
        ROW = matrix.size();
        COL = matrix[0].size();
        count = vector<vector<int>> (ROW, vector<int>(COL, 1));

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (isLowest(matrix, i, j)) {
                    longestSequence(matrix, i, j, -1, 1);
                }
            }
        }

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                res = max(count[i][j], res);
            } 
        }

        return res;
    }
};
