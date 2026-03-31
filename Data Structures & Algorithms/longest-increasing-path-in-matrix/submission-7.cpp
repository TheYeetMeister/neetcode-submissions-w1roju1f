class Solution {
    int directions[4][2]{
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };

    int ROW, COL;

    vector<vector<int>> count;

    int longestSequence(vector<vector<int>>& matrix, int i, int j, int prev) {
        if (i == ROW || i < 0 || 
            j == COL || j < 0 || 
            (prev != -1 && matrix[i][j] >= prev)) {
            return 0;
        }

        if (count[i][j] > 1) {
            return count[i][j];
        }

        for (int k = 0; k < 4; ++k) {
            int row = i + directions[k][0];
            int col = j + directions[k][1];

            count[i][j] = max(count[i][j], 
                    1 + longestSequence(matrix, row, col, matrix[i][j]));
        }

        return count[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 1;
        ROW = matrix.size();
        COL = matrix[0].size();
        count = vector<vector<int>> (ROW, vector<int>(COL, 0));

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                res = max(res, longestSequence(matrix, i, j, -1));
            }
        }

        return res;
    }
};
